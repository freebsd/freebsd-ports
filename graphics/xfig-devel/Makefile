# New ports collection makefile for:	xfig
# Date created:		4 January 1995
# Whom:			roberto
#
# $FreeBSD$
#

PORTNAME=	xfig
PORTVERSION=	3.2.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.xfig.org/xfigdist/ \
		ftp://www-epb.lbl.gov/xfig/%SUBDIR%/
MASTER_SITE_SUBDIR=	. previous_versions
DISTNAME=	${PORTNAME}.${PORTVERSION}.full

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A drawing program for X11

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}

USE_REINPLACE=	yes
USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		xfig.1

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

.include <bsd.port.post.mk>
