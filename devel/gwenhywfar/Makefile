PORTNAME=	gwenhywfar
PORTVERSION=	5.12.2
PORTREVISION?=	0
CATEGORIES=	devel net security
MASTER_SITES=	https://www.aquamaniac.de/rdm/attachments/download/539/

MAINTAINER?=	jhale@FreeBSD.org
COMMENT?=	Multi-platform helper library for networking and security applications
WWW=		https://www.aquamaniac.de/rdm/projects/gwenhywfar

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake libtool localbase:ldflags pathfix pkgconfig
CPE_VENDOR=	aquamaniac
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release="yes" \
		--with-guis="${_GWEN_GUI}"
INSTALL_TARGET=	install-strip

BINARY_ALIAS=	make=${GMAKE}

_GWEN_SHLIB_VER=79
PLIST_SUB=	GWEN_SHLIB_VER="${_GWEN_SHLIB_VER}" \
		GWEN_MAJ_MIN_VER="${PORTVERSION:R}" \
		GWEN_MIN_PATCH_VER="${PORTVERSION:R:E}.${PORTVERSION:E}"

.if !defined(_GWEN_GUI)
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libgpg-error.so:security/libgpg-error

USES+=		gettext iconv:translit

OPTIONS_DEFINE=		DOXYGEN LIBXML2 MEMDEBUG OPENSSL
OPTIONS_DEFAULT=	OPENSSL
OPTIONS_SUB=		yes

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen \
				dot:graphics/graphviz
DOXYGEN_CONFIGURE_ENABLE=	full-doc

LIBXML2_USES=			gnome
LIBXML2_USE=			gnome=libxml2
LIBXML2_CONFIGURE_ON=		--with-libxml2-code=yes

MEMDEBUG_DESC=			Enable memory debugger statistic
MEMDEBUG_CONFIGURE_ENABLE=	memtrace

OPENSSL_USES=			ssl
OPENSSL_CONFIGURE_ENV=		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
				OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
OPENSSL_CONFIGURE_ENV_OFF=	OPENSSL_CFLAGS="" \
				OPENSSL_LIBS=""
.else
LIB_DEPENDS=	libgwenhywfar.so:devel/gwenhywfar

BUILD_WRKSRC=	${WRKSRC}/gui
INSTALL_WRKSRC=	${WRKSRC}/gui/${_GWEN_GUI}

.  if ${_GWEN_GUI} == "fox16"
LIB_DEPENDS+=	libFOX-1.6.so:x11-toolkits/fox16
CONFIGURE_ARGS+=--with-fox-includes=${LOCALBASE}/include/fox-1.6 \
		--with-fox-libs=${LOCALBASE}/lib
CXXFLAGS+=	-Dregister=
.  elif ${_GWEN_GUI} == "gtk2"
LIB_DEPENDS+=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig
USES+=		gettext-runtime gnome
USE_GNOME+=	cairo gdkpixbuf gtk20
.  elif ${_GWEN_GUI} == "gtk3"
LIB_DEPENDS+=	libharfbuzz.so:print/harfbuzz
USES+=		gettext-runtime gnome
USE_GNOME+=	cairo gdkpixbuf gtk30
.  elif ${_GWEN_GUI} == "qt5"
USES+=		compiler:c++11-lang gl qt:5
USE_GL=		gl
USE_QT=		core gui widgets \
		buildtools:build qmake:build
CONFIGURE_ENV+=	QMAKE=${QMAKE} \
		QT_MOC=${MOC} \
		QT_UIC=${UIC}
.  elif ${_GWEN_GUI} == "qt6"
USES+=		compiler:c++17-lang gl qt:6
USE_GL=		opengl
USE_QT=		base
CONFIGURE_ENV+=	QMAKE=${QMAKE} \
		QT_MOC=${MOC} \
		QT_UIC=${UIC}
.  endif
.endif

post-patch:
	${REINPLACE_CMD} -e '/^LIBS/s|$$| @i18n_libs@|' \
		${WRKSRC}/tools/gcttool/Makefile.in \
		${WRKSRC}/tools/typemaker/Makefile.in \
		${WRKSRC}/tools/xmlmerge/Makefile.in
.if defined(_GWEN_GUI)
	@${FIND} ${BUILD_WRKSRC} -name "Makefile.in" -type f | ${XARGS} \
	${REINPLACE_CMD} -e 's|[$$][(]top_builddir[)]/src/[$$][(]gwenhywfar_internal_libname[)]|$$(gwenhywfar_libs)|g' \
			-e 's|[$$][(]builddir[)]/../cpp/libgwengui-cpp.la|-lgwengui-cpp|g' \
			-e 's|[$$][(]top_builddir[)]/gui/cpp/libgwengui-cpp.la|-lgwengui-cpp|g' \
			-e '/^SUBDIRS/s|cpp ||g'
.endif

post-build-DOXYGEN-on:
	@cd ${WRKSRC} && ${SETENVI} ${MAKE_ENV} ${MAKE_CMD} srcdoc

post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/apidoc
	@${FIND} -P ${STAGEDIR}${DOCSDIR} -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}

.include <bsd.port.mk>
