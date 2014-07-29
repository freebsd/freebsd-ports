# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	ocrfeeder
PORTVERSION=	0.7.11
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Document layout analysis and optical character recognition

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}goocanvas>0:${PORTSDIR}/graphics/py-goocanvas \
		${PYTHON_PKGNAMEPREFIX}sane>0:${PORTSDIR}/graphics/py-sane \
		${PYTHON_PKGNAMEPREFIX}reportlab2>0:${PORTSDIR}/print/py-reportlab2 \
		${PYTHON_PKGNAMEPREFIX}enchant>0:${PORTSDIR}/textproc/py-enchant
RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		unpaper:${PORTSDIR}/graphics/unpaper \
		iso-codes>0:${PORTSDIR}/misc/iso-codes \
		${BUILD_DEPENDS}

USES=		desktop-file-utils gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomedocutils librsvg2 pygnomeextras
USE_GHOSTSCRIPT=yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules

post-patch:
	@${REINPLACE_CMD} -e \
		'/gtk.gdk.threads_init/s|^|#|' \
		${WRKSRC}/src/ocrfeeder/studio/studioBuilder.py
	@${REINPLACE_CMD} -e \
		's|/usr/share|${LOCALBASE}/share|' \
		${WRKSRC}/src/ocrfeeder/util/constants.py.in

.include <bsd.port.mk>
