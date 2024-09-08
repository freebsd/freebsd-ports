PORTNAME=	blueprint-compiler
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
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
SHEBANG_FILES=	${PORTNAME}.py
NO_ARCH=	yes

post-patch:
# Derive Python version from Meson
	@${REINPLACE_CMD} -e "s,'python3',," ${WRKSRC}/meson.build

.include <bsd.port.mk>
