# $FreeBSD$

PORTNAME=	gwenhywfar
PORTVERSION=	4.20.2
PORTREVISION?=	0
CATEGORIES=	devel net security
MASTER_SITES=	https://www.aquamaniac.de/rdm/attachments/download/108/

MAINTAINER?=	jhale@FreeBSD.org
COMMENT?=	Multi-platform helper library for networking and security applications

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libgpg-error.so:security/libgpg-error

USES=		gettext gmake iconv:translit libtool pathfix pkgconfig ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release="yes" \
		--with-guis="${SLAVEPORT}"
CPPFLAGS+=	-isystem ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

GWEN_SHLIB_VER=	60
PLIST_SUB=	GWEN_SHLIB_VER="${GWEN_SHLIB_VER}" \
		GWEN_MAJ_MIN_VER="${PORTVERSION:R}"

.if !defined(SLAVEPORT)
OPTIONS_DEFINE=			DOXYGEN MEMDEBUG

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen \
				dot:graphics/graphviz
DOXYGEN_CONFIGURE_ENABLE=	full-doc

MEMDEBUG_DESC=			Enable memory debugger statistic
MEMDEBUG_CONFIGURE_ENABLE=	memtrace
.endif

.include <bsd.port.options.mk>

.if defined(SLAVEPORT)
LIB_DEPENDS+=	libgwenhywfar.so:devel/gwenhywfar
BUILD_WRKSRC=	${WRKSRC}/gui
INSTALL_WRKSRC=	${WRKSRC}/gui/${SLAVEPORT}

.  if ${SLAVEPORT}=="fox16"
LIB_DEPENDS+=	libFOX-1.6.so:x11-toolkits/fox16
CONFIGURE_ARGS+=--with-fox-includes=${LOCALBASE}/include/fox-1.6 \
		--with-fox-libs=${LOCALBASE}/lib
.  elif ${SLAVEPORT}=="gtk2"
LIB_DEPENDS+=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
USES+=		gnome
USE_GNOME+=	cairo gdkpixbuf2 gtk20
.  elif ${SLAVEPORT}=="gtk3"
USES+=		gnome
USE_GNOME+=	cairo gdkpixbuf2 gtk30
.  elif ${SLAVEPORT}=="qt5"
USES+=		compiler:c++11-lang gl qmake:no_env qt:5
USE_GL=		gl
USE_QT=		core gui widgets \
		buildtools_build qmake_build
CONFIGURE_ARGS+=--with-qt5-qmake=${QMAKE} \
		--with-qt5-moc=${MOC} \
		--with-qt5-uic=${UIC}
.  endif
.endif

post-patch:
.if defined(SLAVEPORT)
	@${FIND} ${BUILD_WRKSRC} -name "Makefile.in" -type f | ${XARGS} \
	${REINPLACE_CMD} -e 's|[$$][(]top_builddir[)]/src/[$$][(]gwenhywfar_internal_libname[)]|$$(gwenhywfar_libs)|g' \
			-e 's|[$$][(]builddir[)]/../cpp/libgwengui-cpp.la|-lgwengui-cpp|g' \
			-e 's|[$$][(]top_builddir[)]/gui/cpp/libgwengui-cpp.la|-lgwengui-cpp|g' \
			-e '/^SUBDIRS/s|cpp ||g'
.endif

post-build-DOXYGEN-on:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} srcdoc

post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/apidoc
	@${FIND} -P ${STAGEDIR}${DOCSDIR} -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}

.include <bsd.port.mk>
