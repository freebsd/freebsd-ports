# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	ocrfeeder
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Document layout analysis and optical character recognition

LICENSE=	GPLv3

BUILD_DEPENDS=	goocanvas2>0:${PORTSDIR}/graphics/goocanvas2 \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}sane>0:${PORTSDIR}/graphics/py-sane \
		${PYTHON_PKGNAMEPREFIX}reportlab2>0:${PORTSDIR}/print/py-reportlab2 \
		${PYTHON_PKGNAMEPREFIX}enchant>0:${PORTSDIR}/textproc/py-enchant
RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		unpaper:${PORTSDIR}/graphics/unpaper \
		iso-codes>0:${PORTSDIR}/misc/iso-codes \
		gtkspell3>0:${PORTSDIR}/textproc/gtkspell3 \
		${BUILD_DEPENDS}

USES=		desktop-file-utils gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomedocutils gnomehier gtk30 librsvg2 pygobject3
USE_GHOSTSCRIPT=yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules

post-patch:
	@${REINPLACE_CMD} -e \
		's|"gobject|"gi|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/Gdk.threads_init/s|^|#|' \
		${WRKSRC}/src/ocrfeeder/studio/studioBuilder.py
	@${REINPLACE_CMD} -e \
		's|/usr/share|${LOCALBASE}/share|' \
		${WRKSRC}/src/ocrfeeder/util/constants.py.in

.include <bsd.port.mk>
