# Created by: mwm@mired.org
# $FreeBSD$

PORTNAME=	Pymacs
PORTVERSION=	0.25
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	devel editors python elisp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python package for scripting emacs

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	pinard

USES=		python:2.7
USE_EMACS=	yes
USE_PYTHON=	distutils

pre-configure:
	@(cd ${WRKSRC}; \
		${PYTHON_CMD} pppp -C ppppconfig.py Pymacs.py.in \
			pppp.rst.in pymacs.el.in pymacs.rst.in \
			contrib	tests)

post-build:
	(cd ${WRKSRC} && ${EMACS_CMD} -batch -q -no-site-file -no-init-file \
		-f batch-byte-compile pymacs.el)

post-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} pymacs.el pymacs.elc \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR})

.include <bsd.port.mk>
