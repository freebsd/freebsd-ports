PORTNAME=	upscaler
DISTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Upscale and enhance images
WWW=		https://gitlab.gnome.org/World/Upscaler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	blueprint-compiler:devel/blueprint-compiler
RUN_DEPENDS=	realesrgan-ncnn-vulkan:graphics/realesrgan-ncnn-vulkan

USES=		desktop-file-utils gettext-tools gnome meson python
USE_GITLAB=	yes
USE_GNOME=	gtk40 libadwaita pygobject3
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	Upscaler
GL_COMMIT=	5aaab9ccaf56b3c7a0eb7d1dbba372d8ff970d69
GLIB_SCHEMAS=	io.gitlab.theevilskeleton.Upscaler.gschema.xml

post-patch:
# Derive Python version from Meson
	@${REINPLACE_CMD} -e "s,'python3',," ${WRKSRC}/${PORTNAME}/meson.build

.include <bsd.port.mk>
