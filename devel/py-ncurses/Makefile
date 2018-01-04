# Created by: adsharma@sharams.dhs.org
# $FreeBSD$

PORTNAME=	ncurses
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyncurses-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses binding for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		ncurses python:2.7
USE_PYTHON=	distutils autoplist

post-patch:
.for f in _curses_wrap.c _panel_wrap.c _menu_wrap.c _form_wrap.c
	@${REINPLACE_CMD} -e '45s,^.*$$,#include "py_curses.h",' \
		${WRKSRC}/ncurses/${f}
.endfor
	@${REINPLACE_CMD} -e '/^extern int define_key(/d' \
		${WRKSRC}/ncurses/_curses_wrap.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ncurses/*.so

.include <bsd.port.mk>
