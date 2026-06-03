PORTNAME=	vkrunner
DISTVERSION=	g20260228
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Vulkan shader tester based on shader_runner from Piglit
WWW=		https://gitlab.freedesktop.org/mesa/vkrunner

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	Vulkan non-dispatchable handles are u64 on 32-bit

RUN_DEPENDS=	glslangValidator:graphics/glslang

USES=		cargo

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mesa
GL_TAGNAME=	7bb06ea50d5583f44362168bd6039d86ecd6aba7

PLIST_FILES=	bin/vkrunner

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_DEFAULT=EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.shader_test ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
