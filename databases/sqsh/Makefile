# Created by: Domas Mituzas <midom@dammit.lt>
# $FreeBSD$

PORTNAME=	sqsh
PORTVERSION=	2.5.16.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive tool for querying Sybase database servers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		cmd_connect.c:1897:17: error: use of undeclared identifier 'CS_MAX_CHAR'

LIB_DEPENDS=	libct.so:databases/freetds

USES=		readline tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SYBASE="${LOCALBASE}"
CONFIGURE_ARGS=	--with-readline
ALL_TARGET=	build
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R:R}

PLIST_FILES=	bin/sqsh etc/sqshrc.default man/man1/sqsh.1.gz

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USES=	motif
X11_CONFIGURE_ON=	--with-motif --with-x

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/doc/global.sqshrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sqsh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/sqsh.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/global.sqshrc ${STAGEDIR}${PREFIX}/etc/sqshrc.default

.include <bsd.port.mk>
