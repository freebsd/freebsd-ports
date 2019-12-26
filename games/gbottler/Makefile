# Created by: UMENO Takashi
# $FreeBSD$

PORTNAME=	gbottler
PORTVERSION=	0.1.7
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	OSDN/gbottler/45155

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SSTP Bottle client

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

NO_ARCH=	yes
USES=		gettext-tools gmake gnome python:2.7 shebangfix
SHEBANG_FILES=	src/*.py src/viewer/*.py
USE_GNOME=	pygtk2
MAKE_ARGS=	PYTHON=${PYTHON_CMD}
PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
