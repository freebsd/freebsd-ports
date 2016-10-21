# Created by: glewis@FreeBSD.org
# $FreeBSD$

PORTNAME=	ldmud
PORTVERSION=	3.3.720
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	games net
MASTER_SITES=	http://www.bearnip.com/ftp/mud/ \
		ftp://mud.stack.nl/pub/ldmud/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Modern version of the LPMud game driver

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libpcre.so:devel/pcre

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USES=		iconv pkgconfig
CONFIGURE_ARGS+=--libdir=${DATADIR} \
		--bindir=${PREFIX}/sbin \
		--enable-use-pcre \
		--enable-use-tls=ssl
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
ALL_TARGET=	ldmud
USE_RC_SUBR=	ldmud
MAKE_JOBS_UNSAFE=	yes

USERS=		mud
GROUPS=		mud

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE IPV6 DOCS
OPTIONS_DEFAULT=MYSQL PGSQL SQLITE LPMUD
OPTIONS_SINGLE=	MUDLIB
OPTIONS_SINGLE_MUDLIB=	LPMUD DEMOLIB
OPTIONS_SUB=	yes
LPMUD_DESC=	Install default mudlib (LP-245)
IPV6_CONFIGURE_ENABLE=	use-ipv6
MYSQL_USE=		MYSQL=yes
MYSQL_CONFIGURE_ENABLE=	use-mysql
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ENABLE=	use-pgsql
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ENABLE=use-sqlite

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
LDFLAGS+=	-L${LOCALBASE}/lib/mysql
.endif

post-install:
#	# Install mudlib and other directories
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}/var/log/${PORTNAME} \
		${STAGEDIR}/var/run/${PORTNAME}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/ldmud
.if ${PORT_OPTIONS:MLPMUD}
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mud/lp-245 && ${FIND} . \
		| ${CPIO} -pdmu ${STAGEDIR}${DATADIR}
.else
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mudlib && ${FIND} . \
		| ${CPIO} -pdmu ${STAGEDIR}${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc && ${FIND} . \
		| ${CPIO} -pdmu ${STAGEDIR}${DOCSDIR}
	@${RM} ${STAGEDIR}${DOCSDIR}/Makefile
.endif

.include <bsd.port.mk>
