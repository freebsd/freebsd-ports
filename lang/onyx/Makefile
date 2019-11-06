# Created by: jasone
# $FreeBSD$

PORTNAME=	onyx
PORTVERSION=	5.1.2
PORTREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	http://www.canonware.com/download/onyx/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Embeddable stack-based threaded interpreted language

BROKEN=		unfetchable

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	cook:devel/cook
LIB_DEPENDS=	libpcre.so:devel/pcre

BROKEN_armv6=		fails to compile: building for onyx-5.1.2_6: error code 1
BROKEN_armv7=		fails to compile: building for onyx-5.1.2_6: error code 1
BROKEN_mips=		fails to compile: building for onyx-5.1.2_6: error code 1
BROKEN_mips64=		fails to compile: building for onyx-5.1.2_6: error code 1

USES=		libedit shebangfix tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libedit-prefix=${LOCALBASE} \
		--with-pcre-prefix=${LOCALBASE}
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS
PLIST_SUB=	ONYX_VERSION=${PORTVERSION}

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/onyx/bin/onyx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/onyx_config/bin/onyx_config ${STAGEDIR}${PREFIX}/bin
	${LN} -sf bin/onyx ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${PORTVERSION}
	${LN} -sf bin/onyx_config ${STAGEDIR}${PREFIX}/bin/${PORTNAME}_config-${PORTVERSION}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libonyx
	${INSTALL_DATA} ${WRKSRC}/lib/libonyx/include/libonyx/*.h ${STAGEDIR}${PREFIX}/include/libonyx
	${INSTALL_DATA} ${WRKSRC}/lib/libonyx/lib/libonyx.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/libonyx/lib/libonyx.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/libonyx/lib/libonyx.so.13 ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${DATADIR}/nx/modclopt
	${INSTALL_DATA} ${WRKSRC}/mod/modclopt/nx/modclopt/*.nx ${STAGEDIR}${DATADIR}/nx/modclopt
	${MKDIR} ${STAGEDIR}${DATADIR}/libonyx
	${INSTALL_DATA} ${WRKSRC}/lib/libonyx/src/libonyx_init.nx ${STAGEDIR}${DATADIR}/libonyx
	${MKDIR} ${STAGEDIR}${DATADIR}/nx/modprompt
	${INSTALL_DATA} ${WRKSRC}/mod/modprompt/nx/modprompt/modprompt.nx ${STAGEDIR}${DATADIR}/nx/modprompt
	${INSTALL_MAN} ${WRKSRC}/bin/onyx/man/man1/onyx.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bin/onyx_config/man/man1/onyx_config.1 ${STAGEDIR}${PREFIX}/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	(cd ${WRKSRC}/doc/html/onyx && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html)
	${MKDIR} ${STAGEDIR}${DOCSDIR}/pdf
	${INSTALL_DATA} ${WRKSRC}/doc/pdf/onyx/onyx.pdf ${STAGEDIR}${DOCSDIR}/pdf

.include <bsd.port.mk>
