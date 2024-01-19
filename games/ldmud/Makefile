PORTNAME=	ldmud
PORTVERSION=	3.3.720
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	games net
MASTER_SITES=	http://www.bearnip.com/ftp/mud/ \
		ftp://mud.stack.nl/pub/ldmud/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern version of the LPMud game driver
WWW=		https://www.ldmud.eu/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKRSC}/COPYRIGHT

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		iconv pkgconfig ssl
USE_RC_SUBR=	ldmud

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--libdir=${DATADIR} \
		--bindir=${PREFIX}/sbin \
		--enable-use-pcre \
		--enable-use-tls=ssl

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	ldmud

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USERS=		mud
GROUPS=		mud

OPTIONS_DEFINE=	PGSQL SQLITE IPV6 DOCS
OPTIONS_DEFAULT=PGSQL SQLITE LPMUD
OPTIONS_SINGLE=	MUDLIB
OPTIONS_SINGLE_MUDLIB=	LPMUD DEMOLIB
OPTIONS_SUB=	yes

LPMUD_DESC=	Install default mudlib (LP-245)

IPV6_CONFIGURE_ENABLE=	use-ipv6
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ENABLE=	use-pgsql
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ENABLE=use-sqlite

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}/var/log/${PORTNAME} \
		${STAGEDIR}/var/run/${PORTNAME}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/ldmud

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc && ${FIND} . \
		| ${CPIO} -pdmu ${STAGEDIR}${DOCSDIR}
	@${RM} ${STAGEDIR}${DOCSDIR}/Makefile

post-install-LPMUD-on:
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mud/lp-245 && ${FIND} . \
		| ${CPIO} -pdmu ${STAGEDIR}${DATADIR}

post-install-LPMUD-off:
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mudlib && ${FIND} . \
		| ${CPIO} -pdmu ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
