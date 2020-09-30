# $FreeBSD$

PORTNAME=	geany-plugin-geanypy
PORTVERSION=	${GEANY_VER}
PORTREVISION=	1
PKGNAMESUFFIX=	-gtk2
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-10-15

LIB_DEPENDS=	libgeany.so:devel/geany@gtk2

FLAVORS=	# intentionally left empty

USES=		python:2.7 shebangfix
USE_GNOME=	pygtk2

SHEBANG_FILES=	geanypy/geany/console.py

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
