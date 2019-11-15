# Created by: mek
# $FreeBSD$

PORTNAME=	pvpgn
PORTVERSION=	1.8.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	BERLIOS
DISTFILES=	${EXTRACT_ONLY} pvpgn-support-1.2.tar.gz
DIST_SUBDIR=	pvpgn
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Blizzard Battle.net emulation software

PKGINSTALL?=	${WRKDIR}/pkg-install
PKGDEINSTALL?=	${WRKDIR}/pkg-deinstall
USES=		gmake tar:bzip2
SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g'

USERS=		bnetd
GROUPS=		${USERS}

RC_DIR=		${PREFIX}/etc/rc.d
RC_SUFX=	.sh
SED_SCRIPT+=	-e 's|%%RC_DIR%%|${RC_DIR}|g' \
		-e 's|%%RC_SUFX%%|${RC_SUFX}|g'

PLIST_SUB+=	RC_SUFX=${RC_SUFX}

WRKSRC=		${WRKDIR}/${DISTNAME}/src

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/pvpgn \
		--localstatedir=${DATADIR} \
		--with-libraries=${LOCALBASE}/lib

USE_RC_SUBR=	bnetd

OPTIONS_DEFINE=		D2 MYSQL PGSQL SQLITE3 DOCS
OPTIONS_DEFAULT=	D2
OPTIONS_SUB=		yes

D2_DESC=		Diablo II server (D2CS/D2DBS)
D2_CONFIGURE_ENABLE=	d2cs d2dbs

MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	pgsql

SQLITE3_USES=		sqlite:3
SQLITE3_CONFIGURE_WITH=	sqlite3

## support files

SUPPORT_SUFFX=	.tar.gz
SUPPORT_FILES=	pvpgn-support-1.2

post-extract:
	@${MKDIR} ${WRKSRC}/${SUPPORT_FILES}
	@${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${SUPPORT_FILES}${SUPPORT_SUFFX}

post-build:
	@${SED} "s|%%PVPGN_DIR%%|${DATADIR}|g" ${PKGDIR}/pkg-install > ${WRKDIR}/pkg-install
	@${SED} "s|%%PVPGN_DIR%%|${DATADIR}|g" ${PKGDIR}/pkg-deinstall > ${WRKDIR}/pkg-deinstall

post-install:
	@${ECHO_MSG} ">>>   installing support files ..."
.for i in IX86ver1.mpq PMACver1.mpq XMACver1.mpq bnserver-D2DV.ini \
	bnserver-D2XP.ini bnserver-WAR3.ini bnserver.ini icons-WAR3.bni \
	icons.bni icons_STAR.bni ver-ix86-1.mpq

	${INSTALL_DATA} ${WRKSRC}/${SUPPORT_FILES}/${i} ${STAGEDIR}${DATADIR}/files
.endfor

## Additional documentation

	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in INSTALL.unix PORTS README.fdwatch README.storage bnmotd.txt
	${INSTALL_DATA} ${WRKSRC}/../docs/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
