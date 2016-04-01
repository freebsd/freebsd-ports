# $FreeBSD$

PORTNAME=	gwenhywfar
PORTVERSION=	4.14.0
PORTREVISION?=	1
CATEGORIES=	devel net security
MASTER_SITES=	http://www.aquamaniac.de/sites/download/download.php?package=01&release=01&file=01&dummy=/

MAINTAINER?=	jhale@FreeBSD.org
COMMENT?=	Multi-platform helper library for networking and security applications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls

USES=		gettext gmake iconv libtool pathfix pkgconfig
USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release="yes" \
		--with-guis="${SLAVEPORT}"
CPPFLAGS+=	-DGCRYPT_NO_DEPRECATED -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

GWEN_SHLIB_VER=	60
PLIST_SUB=	GWEN_SHLIB_VER="${GWEN_SHLIB_VER}"

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
.  endif

.  if ${SLAVEPORT}=="gtk2"
USE_GNOME+=	gtk20
.  endif

.  if ${SLAVEPORT}=="qt4"
USE_QT4=	gui moc_build uic_build
QT_NONSTANDARD=	yes
CONFIGURE_ARGS+=--with-qt4-includes=${QT_INCDIR} \
		--with-qt4-libs=${QT_LIBDIR} \
		--with-qt4-moc=${MOC} \
		--with-qt4-uic=${UIC}
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

post-build:
.if ${PORT_OPTIONS:MDOXYGEN}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} srcdoc
.endif

post-install:
.if ${PORT_OPTIONS:MDOXYGEN}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/apidoc
	@${FIND} -P ${STAGEDIR}${DOCSDIR} -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
