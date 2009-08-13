# New ports collection makefile for:    xvile
# Date created:         Wed Nov 26, 1996
# Whom:                 pgf
#
# $FreeBSD$
#

PORTNAME=	xvile
PORTVERSION=	9.7t
CATEGORIES=	editors
MASTER_SITES=	ftp://invisible-island.net/vile/ \
		ftp://dickey.his.com/vile/ \
		ftp://ftp.phred.org/pub/vile/
DISTNAME=	vile-9.7
EXTRACT_SUFX=	.tgz

PATCH_SITES=    ${MASTER_SITES:S,vile/,vile/patches/,g}
PATCHFILES=	vile-9.7a.patch.gz \
		vile-9.7b.patch.gz \
		vile-9.7c.patch.gz \
		vile-9.7d.patch.gz \
		vile-9.7e.patch.gz \
		vile-9.7f.patch.gz \
		vile-9.7g.patch.gz \
		vile-9.7h.patch.gz \
		vile-9.7i.patch.gz \
		vile-9.7j.patch.gz \
		vile-9.7k.patch.gz \
		vile-9.7l.patch.gz \
		vile-9.7m.patch.gz \
		vile-9.7n.patch.gz \
		vile-9.7o.patch.gz \
		vile-9.7p.patch.gz \
		vile-9.7q.patch.gz \
		vile-9.7r.patch.gz \
		vile-9.7s.patch.gz \
		vile-9.7t.patch.gz

MAINTAINER=	gj@FreeBSD.org
COMMENT=	VI Like Emacs, X11 version -- a fully "X aware" vi work-alike

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
USE_XORG=	x11 xpm xext
USE_PERL5=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-libdir-path=${PREFIX}/lib/xvile \
		--datadir=${PREFIX}/share/xvile
MAN1=		xvile.1

OPTIONS= FILTERS "Add support for loadable filters" OFF
OPTIONS+= ICONV "Add support for ICONV" OFF
OPTIONS+= MENUS "Add support for menus" OFF
OPTIONS+= PERL "Add support for perl functions" OFF
OPTIONS+= XAW3D "Use XAW3D to get a 3D effect" OFF

.include <bsd.port.pre.mk>

pre-configure:
.if ! defined(WITH_ICONV)
	@${ECHO_MSG} "Choose the option ICONV if you want to make an xvile which includes"
	@${ECHO_MSG} "ICONV functionality"
.endif
.if ! defined(WITH_MENUS)
	@${ECHO_MSG} "To use xvile with menus, choose the option MENUS,"
	@${ECHO_MSG} "which will also turn on Xaw. If you have Xaw3d, you can use it"
	@${ECHO_MSG} "by also choosing the option XAW3D."
.endif

.if ! defined(WITH_PERL)
	@${ECHO_MSG} "To use xvile with PERL, choose the option PERL."
.endif

.if ! defined(WITH_FILTERS)
	@${ECHO_MSG} "Choose the option FILTERS if you want to make an xvile which will"
	@${ECHO_MSG} "dynamically load filters as needed."
.endif

.if defined(WITH_ICONV)
CONFIGURE_ARGS+=	--with-iconv
USE_ICONV=	yes
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

.if defined(WITH_MENUS)
CONFIGURE_ARGS+= --with-screen=Xaw
.if defined(WITH_XAW3D)
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
CONFIGURE_ARGS+=	--with-Xaw3d
.endif
.else
CONFIGURE_ARGS+=	--with-screen=x11
.endif

.if defined(WITH_PERL)
CONFIGURE_ARGS+= --with-perl
PLIST=		${PKGDIR}/pkg-plist.perl
USE_PERL5=	yes
.endif

.if defined(WITH_FILTERS)
CONFIGURE_ARGS+=	--with-loadable-filters
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

.include <bsd.port.post.mk>
