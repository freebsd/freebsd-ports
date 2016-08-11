# $FreeBSD$

PORTNAME=	libsidplayfp
PORTVERSION=	1.8.6
CATEGORIES=	audio
MASTER_SITES=	SF/sidplay-residfp/libsidplayfp/${PORTVERSION:R}

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Library to play Commodore 64 music derived from libsidplay2

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	NEWS README TODO

OPTIONS_DEFINE=	DEBUG DOCS DOXYGEN
DEBUG_CONFIGURE_ON=	--enable-debug=full
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

OPTIONS_GROUP=	OPTIMIZATION
OPTIONS_GROUP_OPTIMIZATION=	BHINTS INLINE MMX
OPTIONS_DEFAULT=	BHINTS INLINE

OPTIMIZATION_DESC=	Increase performance by optimization
BHINTS_DESC=	Enable branch hints in reSID engine
BHINTS_CONFIGURE_ENABLE=	branch-hints
INLINE_DESC=	Enable inlining in reSID engine at bigger code size
INLINE_CONFIGURE_ENABLE=	inline
MMX_DESC=	Enable MMX code in reSIDfp for old x86 non-SSE2 CPU
MMX_CONFIGURE_ENABLE=	mmx

BUILD_DEPENDS+=	xa65:devel/xa65

SIDPLAYFP_SHLIB_VERSION=	4.2.7
STILVIEW_SHLIB_VERSION=	0.0.3
PLIST_SUB+=	\
	SIDPLAYFP_SHLIB_VER=${SIDPLAYFP_SHLIB_VERSION:C/\.[[:digit:].]+//} \
	SIDPLAYFP_SHLIB_VERSION=${SIDPLAYFP_SHLIB_VERSION} \
	STILVIEW_SHLIB_VER=${STILVIEW_SHLIB_VERSION:C/\.[[:digit:].]+//} \
	STILVIEW_SHLIB_VERSION=${STILVIEW_SHLIB_VERSION}

post-build-DOXYGEN-on:
	${MAKE_CMD} doc -C ${WRKSRC}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${STAGEDIR}${DOCSDIR}/html
	@${FIND} ${STAGEDIR}${DOCSDIR}/html -type f | \
		${SED} 's|${STAGEDIR}${PREFIX}/||' > ${WRKDIR}/PLIST.doc
	@${SED} -i -e '/PLIST.doc/ r ${WRKDIR}/PLIST.doc' ${TMPPLIST}

.include <bsd.port.mk>
