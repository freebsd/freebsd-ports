PORTNAME=	blueprint-compiler
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
CATEGORIES=	devel

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Markup language for GTK user interfaces
WWW=		https://gitlab.gnome.org/jwestman/blueprint-compiler

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	gtk4>0:x11-toolkits/gtk40

USES=		gnome meson python shebangfix
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	jwestman
USE_GNOME=	pygobject3
SHEBANG_FILES=	${PORTNAME}.py docs/collect-sections.py
NO_ARCH=	yes

post-patch:
# Derive Python version from Meson
	@${REINPLACE_CMD} -e "s,'python3','${PYTHON_CMD}'," ${WRKSRC}/meson.build

post-stage:
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
