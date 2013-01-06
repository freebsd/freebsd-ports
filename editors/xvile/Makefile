# Created by: pgf
# $FreeBSD$

PORTNAME=	xvile
PORTVERSION=	9.8g
CATEGORIES=	editors
MASTER_SITES=	ftp://invisible-island.net/vile/current/ \
		ftp://dickey.his.com/vile/current/ \
		ftp://ftp.phred.org/pub/vile/current/
DISTNAME=	vile-9.8g
EXTRACT_SUFX=	.tgz

PATCH_SITES=    ${MASTER_SITES:S,vile/current/,vile/patches/,g}
PATCHFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VI Like Emacs, X11 version -- a fully "X aware" vi work-alike

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
USE_XORG=	x11 xpm xext
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-libdir-path=${PREFIX}/lib/xvile \
		--datadir=${PREFIX}/share/xvile
MAN1=		xvile.1

OPTIONS_DEFINE=	FILTERS ICONV MENUS PERL XAW3D DOCS
FILTERS_DESC=	Loadable filters
MENUS_DESC=	Support for menus
XAW3D_DESC=	XAW3D to get a 3D effect

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=	--with-iconv
USE_ICONV=	yes
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

.if ${PORT_OPTIONS:MMENUS}
CONFIGURE_ARGS+= --with-screen=Xaw
.if ${PORT_OPTIONS:MXAW3D}
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
CONFIGURE_ARGS+=	--with-Xaw3d
.endif
.else
CONFIGURE_ARGS+=	--with-screen=x11
.endif

.if ${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+= --with-perl
PLIST=		${PKGDIR}/pkg-plist.perl
USE_PERL5=	yes
.endif

.if ${PORT_OPTIONS:MFILTERS}
CONFIGURE_ARGS+=	--with-loadable-filters
PLIST=		${PKGDIR}/pkg-plist.filt
.endif

.if ${PORT_OPTIONS:MPERL} && ${PORT_OPTIONS:MFILTERS}
PLIST=		${PKGDIR}/pkg-plist.perl+filt
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@if ! [ -d ${PREFIX}/share/doc/xvile ]; then ${MKDIR} ${PREFIX}/share/doc/xvile; fi
	${INSTALL_DATA} ${WRKSRC}/doc/*.doc ${PREFIX}/share/doc/xvile
.endif
	@if ! [ -d ${PREFIX}/share/xvile/macros ]; then ${MKDIR} ${PREFIX}/share/xvile/macros; fi
	${INSTALL_DATA} ${WRKSRC}/macros/*.rc ${PREFIX}/share/xvile/macros
	${INSTALL_SCRIPT} ${WRKSRC}/macros/vile-pager ${PREFIX}/share/xvile/macros
	@${ECHO_MSG} "Look in ${PREFIX}/share/doc/xvile for documentation."
	@${ECHO_MSG} "Look in ${PREFIX}/share/xvile/macros for macros."

.include <bsd.port.mk>
