# New ports collection makefile for:	smalltalk
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $FreeBSD$
#

PORTNAME=	smalltalk
PORTVERSION=	3.2.4
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU Smalltalk

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		gawk:${PORTSDIR}/lang/gawk
LIB_DEPENDS=	gdbm:${PORTSDIR}/databases/gdbm \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		cairo:${PORTSDIR}/graphics/cairo

OPTIONS_DEFINE=	TCL PGSQL SDL
OPTIONS_DEFAULT=TCL PGSQL SDL

USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack pkgconfig pango
USE_ICONV=	yes
USE_SQLITE=	yes
USE_GMAKE=	yes
USE_XORG=	ice xi xmu
USE_GL=		gl glut
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_EMACS=no
CONFIGURE_ARGS=	--enable-generational-gc=no \
		--enable-gtk=no \
		--with-emacs=no \
		--with-gmp=no
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"
PORTDATA=	*

.ifdef	NOPORTDATA
IGNORE=		smalltalk requires port data, unset NOPORTDATA to install
.endif

MAN1=		gst.1 gst-load.1 gst-package.1 gst-sunit.1 gst-config.1 \
		gst-convert.1 gst-doc.1 gst-profile.1
MLINKS=		gst-load.1 gst-reload.1
INFO=		gst gst-base gst-libs

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCL}
LIB_DEPENDS+=		tk84:${PORTSDIR}/x11-toolkits/tk84
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl8.4 \
			--with-tk=${LOCALBASE}/lib/tk8.4
PLIST_SUB+=		TCLTK=""
.else
CONFIGURE_ARGS+=	--with-tcl=no
PLIST_SUB+=		TCLTK="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
. include "${PORTSDIR}/Mk/bsd.database.mk"
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	image mixer sdl sound ttf
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Fails to install on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
		-e 's/ia64-\*-\* /&|amd64-*-* /' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/x86_64-\*-freebsd\* /&| amd64-*-freebsd* / ' \
		${WRKSRC}/libffi/configure
	@${REINPLACE_CMD} -e 's/lrintl (truncl/lroundl (truncl/' \
		${WRKSRC}/libgst/prims.def \
		${WRKSRC}/libgst/prims.inl

post-build:
	@${SED} -e 's|@bindir@|${PREFIX}/bin|g' \
		${WRKSRC}/gst-mode.el.in > ${WRKSRC}/gst-mode.el

post-install:
	@${MKDIR} ${DATADIR}/gtk
	@${TOUCH} ${DATADIR}/gtk/.keep_me
	${INSTALL_DATA} ${WRKSRC}/*.el ${PREFIX}/share/emacs/site-lisp

.include <bsd.port.post.mk>
