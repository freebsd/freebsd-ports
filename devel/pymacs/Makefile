# Created by: mwm@mired.org
# $FreeBSD$

PORTNAME=	Pymacs
PORTVERSION=	0.25
CATEGORIES=	devel editors python elisp
MASTER_SITES=	http://github.com/pinard/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	mwm@mired.org
COMMENT=	A Python package for scripting emacs

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_PYTHON_PREFIX=	yes
USE_EMACS=	yes

NO_STAGE=	yes
pre-configure:
	@(cd ${WRKSRC}; \
		${PYTHON_CMD} pppp -C ppppconfig.py Pymacs.py.in \
			pppp.rst.in pymacs.el.in pymacs.rst.in \
			contrib	tests)

# Install the emacs side of things
post-install:
	${INSTALL_DATA} ${WRKSRC}/pymacs.el ${PREFIX}/${EMACS_SITE_LISPDIR}
	${EMACS_NAME} -batch -f batch-byte-compile \
		${PREFIX}/${EMACS_SITE_LISPDIR}/pymacs.el

.include <bsd.port.mk>
