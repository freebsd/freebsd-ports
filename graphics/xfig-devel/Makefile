# New ports collection makefile for:	xfig
# Version required:	3.2
# Date created:		4 January 1995
# Whom:			roberto
#
# $FreeBSD$
#

DISTNAME=	xfig.3.2.2
PKGNAME=	xfig-3.2.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/xfig

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d
RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

.if defined(WANT_GS_SUPPORT)
RUN_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript5
.endif

USE_IMAKE=	yes
MAN1=		xfig.1

MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  \
		XFIGLIBDIR=${PREFIX}/lib/X11/xfig  -f

.if !defined(WANT_GS_SUPPORT)
post-patch:
	@( cd ${WRKSRC}; ${PERL} -pi -e 's,-DGSBIT ,,' Imakefile )
.endif

.include <bsd.port.mk>
