PORTNAME=	blueprint-compiler
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Markup language for GTK user interfaces
WWW=		https://gitlab.gnome.org/jwestman/blueprint-compiler

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	gtk4>0:x11-toolkits/gtk40

USES=		gnome meson python shebangfix
USE_GITLAB=	yes
USE_GNOME=	pygobject3
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	jwestman
GL_COMMIT=	aa7679618e864748f4f4d8f15283906e712752fe
SHEBANG_FILES=	${PORTNAME}.py
NO_ARCH=	yes

post-patch:
# Derive Python version from Meson
	@${REINPLACE_CMD} -e "s,'python3',," ${WRKSRC}/meson.build

.include <bsd.port.mk>
