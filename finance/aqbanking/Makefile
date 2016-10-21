# $FreeBSD$

PORTNAME=	aqbanking
PORTVERSION=	5.6.12
CATEGORIES=	finance
MASTER_SITES=	http://www.aquamaniac.de/sites/download/download.php?package=03&release=208&file=01&dummy=/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Online banking interface and financial data framework

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libgwenhywfar.so:devel/gwenhywfar \
		libltdl.so:devel/libltdl \
		libgmp.so:math/gmp \
		libgnutls.so:security/gnutls

USES=		gettext gmake libtool localbase pathfix pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release="yes"
LIBS+=		-lintl
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

AQB_SHLIB_VER=	35
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

post-build-DOXYGEN-on:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} srcdoc

post-install-DOCS-off:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/apidoc
	@${FIND} -P ${STAGEDIR}${DOCSDIR} -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}

.include <bsd.port.mk>
