# New ports collection makefile for:	xfig
# Date created:		4 January 1995
# Whom:			roberto
#
# $FreeBSD$
#

PORTNAME=	xfig
PORTVERSION=	3.2.3d
CATEGORIES=	graphics
MASTER_SITES=	http://www.xfig.org/xfigdist/ \
		ftp://www-epb.lbl.gov/xfig/
MASTER_SITE_SUBDIR=	applications/drawing_tools/xfig
DISTNAME=	${PORTNAME}.${PORTVERSION}.full

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		xfig.1

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install.all
.endif

pre-everything::
.if !defined(WITHOUT_GHOSTSCRIPT)
	@${ECHO_MSG} "To build this port without Ghostscript support,"
	@${ECHO_MSG} "define \"WITHOUT_GHOSTSCRIPT\"."
.endif

post-extract:
	@${CP} ${WRKSRC}/Doc/xfig.man ${WRKSRC}

post-patch:
.if defined(WITHOUT_GHOSTSCRIPT)
	@${PERL} -pi -e 's|-DGSBIT ||g' ${WRKSRC}/Imakefile
.endif

.include <bsd.port.mk>
