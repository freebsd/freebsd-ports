# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	dreampie
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python shell which is designed to be reliable and fun

LICENSE=	GPLv3

DEPRECATED=	Old, uses EOLed python27
EXPIRATION_DATE=	2020-02-28

USE_GNOME=	pygtk2 pygtksourceview
USES=		gnome python:2.7
USE_PYTHON=	distutils autoplist

pre-patch:
	@${REINPLACE_CMD} -e "s|share/man/man1|man/man1|" ${WRKSRC}/setup.py

.include <bsd.port.mk>
