# New ports collection makefile for:	py-xdg
# Date created:		2004-06-25
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#    $MCom: ports/devel/py-xdg/Makefile,v 1.2 2006/09/02 14:38:55 ahze Exp $
#

PORTNAME=	xdg
PORTVERSION=	0.15
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://www.freedesktop.org/~lanius/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A python library to access freedesktop.org standards

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|/etc|${LOCALBASE}/etc|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/xdg/BaseDirectory.py \
			${WRKSRC}/xdg/IconTheme.py

.include <bsd.port.mk>
