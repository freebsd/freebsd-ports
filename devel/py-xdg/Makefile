# New ports collection makefile for:	py-xdg
# Date created:		2004-06-25
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	xdg
PORTVERSION=	0.6
CATEGORIES=	devel python
MASTER_SITES=	http://freedesktop.org/Software/pyxdg/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ahze@ahze.net
COMMENT=	A python library to access freedesktop.org standards

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g ; \
		s|/usr/share|/usr/share:${X11BASE}/share|g' \
		${WRKSRC}/xdg/BaseDirectory.py
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/xdg/IconTheme.py

.include <bsd.port.mk>
