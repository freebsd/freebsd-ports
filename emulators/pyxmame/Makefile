# New ports collection makefile for:	pyxmame
# Date created:		2006-08-01
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyxmame
PORTVERSION=	0.4.0
PORTREVISION=	3
CATEGORIES=	emulators python
MASTER_SITES=	SF/${PORTNAME}/tgz%20source/${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Simple frontend for the xmame

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		xmame:${PORTSDIR}/emulators/xmame

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/games|${PREFIX}/share|g ; \
		s|/usr/share/pixmaps|${PREFIX}/share/pixmaps|g' \
			${WRKSRC}/config/pyxmamerc

.include <bsd.port.mk>
