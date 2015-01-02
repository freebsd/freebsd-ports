# $FreeBSD$

PORTNAME=	gwenhywfar
PORTVERSION=	4.3.3
PORTREVISION?=	8
CATEGORIES=	devel net security
MASTER_SITES=	http://www.aquamaniac.de/sites/download/download.php?package=01&release=67&file=01&dummy=/

MAINTAINER?=	jhale@FreeBSD.org
COMMENT?=	Multi-platform helper library for networking and security applications

LICENSE=	LGPL21

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgnutls.so:${PORTSDIR}/security/gnutls

USES=		pathfix pkgconfig gettext gmake libtool
USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release="yes" \
		--with-guis="${SLAVEPORT}"
CPPFLAGS+=	-DGCRYPT_NO_DEPRECATED -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

PLIST_SUB=	GWEN_SHLIB_VER="${GWEN_SHLIB_VER}"
USE_LDCONFIG=	yes

GWEN_SHLIB_VER=	60

.if !defined(SLAVEPORT)
OPTIONS_DEFINE=			DOXYGEN MEMDEBUG

DOXYGEN_BUILD_DEPENDS=		doxygen:${PORTSDIR}/devel/doxygen \
				dot:${PORTSDIR}/graphics/graphviz
DOXYGEN_CONFIGURE_ENABLE=	full-doc

MEMDEBUG_DESC=			Enable memory debugger statistic
MEMDEBUG_CONFIGURE_ENABLE=	memtrace
.endif

.include <bsd.port.options.mk>

.if defined(SLAVEPORT)
LIB_DEPENDS+=	libgwenhywfar.so:${PORTSDIR}/devel/gwenhywfar
BUILD_WRKSRC=	${WRKSRC}/gui
INSTALL_WRKSRC=	${WRKSRC}/gui/${SLAVEPORT}

.if ${SLAVEPORT}=="fox16"
LIB_DEPENDS+=	libFOX-1.6.so:${PORTSDIR}/x11-toolkits/fox16
CPPFLAGS+=	-I${LOCALBASE}/include
.endif

.if ${SLAVEPORT}=="gtk2"
USE_GNOME+=	gtk20
.endif

.if ${SLAVEPORT}=="qt4"
USE_QT4=	gui moc_build uic_build
QT_NONSTANDARD=	yes
.endif
.endif

post-patch:
.if defined(SLAVEPORT)
	@${FIND} ${BUILD_WRKSRC} -name "Makefile.in" -type f | ${XARGS} \
	${REINPLACE_CMD} -e 's|[$$][(]top_builddir[)]/src/[$$][(]gwenhywfar_internal_libname[)]|$$(gwenhywfar_libs)|g'
.endif

post-build:
.if ${PORT_OPTIONS:MDOXYGEN}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} srcdoc
.endif

post-install:
.if ${PORT_OPTIONS:MDOXYGEN}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/apidoc
	@${FIND} -P ${STAGEDIR}${DOCSDIR} -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
