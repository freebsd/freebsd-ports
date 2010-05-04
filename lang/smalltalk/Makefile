# New ports collection makefile for:	smalltalk
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $FreeBSD$
#

PORTNAME=	smalltalk
PORTVERSION=	3.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU Smalltalk

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		gawk:${PORTSDIR}/lang/gawk
LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm \
		execinfo.1:${PORTSDIR}/devel/libexecinfo \
		cairo.2:${PORTSDIR}/graphics/cairo

OPTIONS=	TCLTK "Enable Tcl/Tk binding" on \
		PGSQL "PostgreSQL binding" on \
		SDL "SDL binding" on

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack gnometarget pkgconfig pango
USE_ICONV=	yes
USE_SQLITE=	yes
USE_GMAKE=	yes
USE_GL=		gl glut
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_prog_EMACS=no
CONFIGURE_ARGS=	--enable-generational-gc=no \
		--enable-gtk=no \
		--with-emacs=no \
		--with-gmp=no
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"
PORTDATA=	*

MAN1=		gst.1 gst-load.1 gst-package.1 gst-sunit.1 gst-config.1 \
		gst-convert.1 gst-doc.1 gst-profile.1
MLINKS=		gst-load.1 gst-reload.1
INFO=		gst gst-base gst-libs

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Fails to install on sparc64
.endif

.if ${OSVERSION} < 700000
BROKEN=		Bad pkg-plist (fails to detect sdl parts)
.endif

.if defined(WITHOUT_TCLTK)
CONFIGURE_ARGS+=	--with-tcl=no
PLIST_SUB+=	TCLTK="@comment "
.else
LIB_DEPENDS+=	tk84.1:${PORTSDIR}/x11-toolkits/tk84
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl8.4 \
			--with-tk=${LOCALBASE}/lib/tk8.4
PLIST_SUB+=	TCLTK=""
.endif

.if defined(WITHOUT_PGSQL)
PLIST_SUB+=	PGSQL="@comment "
.else
USE_PGSQL=	yes
.include "${PORTSDIR}/Mk/bsd.database.mk"
PLIST_SUB+=	PGSQL=""
.endif

.if defined(WITHOUT_SDL)
PLIST_SUB+=	SDL="@comment "
.else
USE_SDL=	image mixer sdl sound ttf
PLIST_SUB+=	SDL=""
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
