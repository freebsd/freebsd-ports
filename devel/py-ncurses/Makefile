# New ports collection makefile for:	pyncurses
# Date created:				Tue May 16 22:15:11 PDT 2000
# Whom:					adsharma@sharams.dhs.org
#
# $FreeBSD$
#

PORTNAME=	ncurses
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyncurses
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyncurses-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A ncurses binding for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

post-patch:
.if ${PYTHON_REL} >= 230
.for f in _curses_wrap.c _panel_wrap.c _menu_wrap.c _form_wrap.c
	@${REINPLACE_CMD} -e '45s,^.*$$,#include "py_curses.h",' \
		${WRKSRC}/ncurses/${f}
.endfor
.endif

.include <bsd.port.post.mk>
