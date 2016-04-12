# Created by: Martin Preuss <martin@libchipcard.de>
# $FreeBSD$

PORTNAME=	libchipcard
PORTVERSION=	5.0.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.aquamaniac.de/sites/download/download.php?package=02&release=26&file=01&dummy=/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for easy access to chipcards

LICENSE=	LGPL21

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite \
		libgwenhywfar.so:devel/gwenhywfar

USES=		gmake libtool
USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	aq_distrib_name="FreeBSD"
CONFIGURE_ARGS+=--enable-release="yes" \
		--with-pcsc-includes=${LOCALBASE}/include \
		--with-pcsc-libs=${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PLIST_SUB=	GWEN_SHLIB_VER="${GWEN_SHLIB_VER}"
USE_LDCONFIG=	yes

GWEN_SHLIB_VER=	60

OPTIONS_DEFINE=			DOXYGEN MEMDEBUG

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen \
				dot:graphics/graphviz
DOXYGEN_CONFIGURE_ENABLE=	full-doc

MEMDEBUG_DESC=			Enable memory debugger statistic
MEMDEBUG_CONFIGURE_ENABLE=	memtrace

post-patch:
	${REINPLACE_CMD} -e 's|aq_endian\" ==|aq_endian\" =|g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|find chipcard|find libchipcard5|' \
		${WRKSRC}/Makefile.in

post-build-DOXYGEN-on:
	@cd ${WRKSRC} && ${MAKE_CMD} srcdoc

post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/apidoc
	@${FIND} -P ${STAGEDIR}${DOCSDIR} -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}

.include <bsd.port.mk>
