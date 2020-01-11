# $FreeBSD$

PORTNAME=	cherrytree
DISTVERSION=	0.38.11
CATEGORIES=	deskutils
MASTER_SITES=	https://www.giuspen.com/software/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Hierarchical note taking application

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gtksourceview>0:x11-toolkits/py-gtksourceview

USES=		desktop-file-utils gettext-tools python:2.7 shared-mime-info shebangfix tar:xz
SHEBANG_FILES=	glade/svg_to_png.py
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.pre.mk>

# PYDISTUTILS_INSTALLNOSINGLE is deprecated so...
PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}

.include <bsd.port.post.mk>
