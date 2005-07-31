# New ports collection makefile for:    xvile
# Date created:         Wed Nov 26, 1996
# Whom:                 pgf
#
# $FreeBSD$
#

PORTNAME=	xvile
PORTVERSION=	9.5
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.phred.org/pub/vile/ \
		ftp://invisible-island.net/vile/ \
		ftp://dickey.his.com/vile/
DISTNAME=	vile-9.5
EXTRACT_SUFX=	.tgz

PATCH_SITES=    ${MASTER_SITES:S,vile/,vile/patches/,g}

MAINTAINER=	gj@FreeBSD.org
COMMENT=	VI Like Emacs, X11 version -- a fully "X aware" vi work-alike

USE_XLIB=	yes
MAKEFILE=	makefile
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-libdir-path=${PREFIX}/lib/xvile \
		--datadir=${PREFIX}/share/xvile
MAN1=		xvile.1

.if defined(WITH_ALL)
WITH_FILTERS=1
WITH_MENUS=1
WITH_PERL=1
WITH_XAW3D=1
.endif

pre-configure:
.if ! defined(WITH_MENUS)
	@${ECHO_MSG} "To use xvile with menus, set the environment variable WITH_MENUS,"
	@${ECHO_MSG} "which will also turn on Xaw. If you have Xaw3d, you can use it"
	@${ECHO_MSG} "by also settting the environment variable WITH_XAW3D."
.endif

.if ! defined(WITH_PERL)
	@${ECHO_MSG} "To use xvile with PERL, set the environment variable WITH_PERL."
.endif

.if ! defined(WITH_FILTERS)
	@${ECHO_MSG} "Define WITH_FILTERS if you want to make an xvile which will"
	@${ECHO_MSG} "dynamically load filters as needed."
.endif

.if defined(WITH_MENUS)
CONFIGURE_ARGS+= --with-screen=Xaw
.if defined(WITH_XAW3D)
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
CONFIGURE_ARGS+= --with-Xaw3d
.endif
.else
CONFIGURE_ARGS+= --with-screen=x11
.endif

.if defined(WITH_PERL)
CONFIGURE_ARGS+= --with-perl
PLIST=		${PKGDIR}/pkg-plist.perl
USE_PERL5=	yes
.endif

.if defined(WITH_FILTERS)
CONFIG_ARGS+= --with-loadable-filters
PLIST=		${PKGDIR}/pkg-plist.filt
.endif

.if defined(WITH_PERL) && defined(WITH_FILTERS)
PLIST=		${PKGDIR}/pkg-plist.perl+filt
.endif

post-install:
.if !defined(NOPORTDOCS)
	@if ! [ -d ${PREFIX}/share/doc/xvile ]; then ${MKDIR} ${PREFIX}/share/doc/xvile; fi
	${INSTALL_DATA} ${WRKSRC}/doc/*.doc ${PREFIX}/share/doc/xvile
.endif
	@if ! [ -d ${PREFIX}/share/xvile/macros ]; then ${MKDIR} ${PREFIX}/share/xvile/macros; fi
	${INSTALL_DATA} ${WRKSRC}/macros/*.rc ${PREFIX}/share/xvile/macros
	${INSTALL_SCRIPT} ${WRKSRC}/macros/vile-pager ${PREFIX}/share/xvile/macros
	@${ECHO_MSG} "Look in ${PREFIX}/share/doc/xvile for documentation."
	@${ECHO_MSG} "Look in ${PREFIX}/share/xvile/macros for macros."

.include <bsd.port.mk>
