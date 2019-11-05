# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfpovray
PORTVERSION=	1.3.1
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	http://www.batse.msfc.nasa.gov/~mallozzi/home/software/xforms/src/ \
		SUNSITE/apps/graphics/rays/pov

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical interface to POV-Ray

LIB_DEPENDS=	libforms.so:x11-toolkits/xforms
RUN_DEPENDS=	povray:graphics/povray-meta

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz uidfix xorg
USE_XORG=	x11 xext xpm
MAKEFILE=	${FILESDIR}/BSDmakefile
MAKE_ENV=	DOCSDIR="${DOCSDIR}"

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g;" ${WRKSRC}/src/xfpovray.h
	@${REINPLACE_CMD} -e "s|fl_drw_box|fl_draw_box|g;"	\
		${WRKSRC}/flx/flx_return_button/flx_return_button.c

post-install:
	${MV} ${WRKSRC}/help ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
