# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	ocrfeeder
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Document layout analysis and optical character recognition

LICENSE=	GPLv3

BUILD_DEPENDS=	goocanvas2>0:graphics/goocanvas2 \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}sane>0:graphics/py-sane \
		${PYTHON_PKGNAMEPREFIX}reportlab2>0:print/py-reportlab2 \
		${PYTHON_PKGNAMEPREFIX}enchant>0:textproc/py-enchant
RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		unpaper:graphics/unpaper \
		iso-codes>0:misc/iso-codes \
		gtkspell3>0:textproc/gtkspell3 \
		${BUILD_DEPENDS}

NO_ARCH=	yes

USES=		desktop-file-utils gettext ghostscript gmake pkgconfig \
		python tar:xz
USE_GNOME=	gnomedocutils gtk30 intltool librsvg2 pygobject3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
