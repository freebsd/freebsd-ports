# New ports collection makefile for:	xfig
# Date created:		4 January 1995
# Whom:			roberto
#
# $FreeBSD$
#

PORTNAME=	xfig
PORTVERSION=	3.2.5.a5
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://xfig.org/software/xfig/${PORTVERSION:R}-alpha/
DISTNAME=	${PORTNAME}.${PORTVERSION:S,.a,-alpha,}.full

MAINTAINER=	lesi@FreeBSD.org
COMMENT=	A drawing program for X11 (Alpha version)

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d
RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

CONFLICTS=	xfig-[12].* xfig-3.1* xfig-3.2.[1234]*

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION:S,.a,-alpha,}

LATEST_LINK=	xfig-devel
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xi xmu xpm xt
MAN1=		xfig.1

MAKE_ENV+=	DOCSDIR=${DOCSDIR}

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install.all
.endif

OPTIONS=	GHOSTSCRIPT "Ghostscript support" on

.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${WRKSRC}/Doc/xfig.man ${WRKSRC}

post-patch:
.if defined(WITHOUT_GHOSTSCRIPT)
	@${REINPLACE_CMD} -e 's|-DGSBIT ||g' ${WRKSRC}/Imakefile
.endif
	echo "NOPORTDOCS=${NOPORTDOCS}"

.include <bsd.port.post.mk>
