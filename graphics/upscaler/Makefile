PORTNAME=	upscaler
DISTVERSION=	1.6.3
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Upscale and enhance images
WWW=		https://gitlab.gnome.org/World/Upscaler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	blueprint-compiler:devel/blueprint-compiler
RUN_DEPENDS=	realesrgan-ncnn-vulkan:graphics/realesrgan-ncnn-vulkan \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vulkan>0:graphics/py-vulkan@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools gnome meson python
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	Upscaler
USE_GNOME=	glib20 gtk40 libadwaita pango pygobject3
GLIB_SCHEMAS=	io.gitlab.theevilskeleton.Upscaler.gschema.xml

post-patch:
# Derive Python version from Meson
	@${REINPLACE_CMD} -e "s,'python3',," ${WRKSRC}/${PORTNAME}/meson.build

.include <bsd.port.mk>
