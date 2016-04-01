# $FreeBSD$

PORTNAME=	aqbanking
PORTVERSION=	5.5.1
CATEGORIES=	finance
MASTER_SITES=	http://www.aquamaniac.de/sites/download/download.php?package=03&release=118&file=01&dummy=/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Online banking interface and financial data framework

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libgwenhywfar.so:devel/gwenhywfar \
		libgmp.so:math/gmp

USES=		compiler:features gettext gmake libtool pathfix pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release="yes"
CONFIGURE_ENV=	COMPILER_TYPE="${COMPILER_TYPE}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lintl
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

AQB_SHLIB_VER=	34
PLIST_SUB=	AQB_SHLIB_VER="${AQB_SHLIB_VER}"

OPTIONS_DEFINE=		DOCS DOXYGEN EBICS KTOBLZCHECK
OPTIONS_DEFAULT=	KTOBLZCHECK
OPTIONS_SUB=		yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_CONFIGURE_ENABLE=	full-doc

EBICS_DESC=		Enable EBICS backend
EBICS_LIB_DEPENDS=	libxmlsec1-gnutls.so:security/xmlsec1
EBICS_USE=		GNOME=libxml2,libxslt
EBICS_CONFIGURE_OFF=	--with-backends="aqhbci aqnone aqofxconnect"

KTOBLZCHECK_DESC=	Enable KtoBlzCheck support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEBICS} && !exists(${LOCALBASE}/libdata/pkgconfig/xmlsec1-gnutls.pc)
IGNORE=		(Re)Install security/xmlsec1 with the GNUTLS option ON
.endif

.if ${PORT_OPTIONS:MKTOBLZCHECK} || exists(${LOCALBASE}/lib/libktoblzcheck.so)
LIB_DEPENDS+=	libktoblzcheck.so:finance/ktoblzcheck
.endif

.if ${PORT_OPTIONS:MDOCS} && !${PORT_OPTIONS:MDOXYGEN}
PORTDOCS=	*
.endif

post-build:
.if ${PORT_OPTIONS:MDOXYGEN}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} srcdoc
.endif

post-install:
.if !${PORT_OPTIONS:MDOCS}
	@${RM} -rf ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MDOXYGEN}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/apidoc
	@${FIND} -P ${STAGEDIR}${DOCSDIR} -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
