# $FreeBSD$

PORTNAME=	ibus-hangul
PORTVERSION=	1.5.0
CATEGORIES=	korean
MASTER_SITES=	https://github.com/choehwanjin/ibus-hangul/releases/download/${PORTVERSION}/

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hangul input engine for IBus

LICENSE=	GPLv2

LIB_DEPENDS=	libhangul.so:korean/libhangul \
		libibus-1.0.so:textproc/ibus

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	gtk30 intlhack pygobject3
USES=		gettext gmake libtool pkgconfig python
USE_PYTHON=	py3kplist

.include <bsd.port.mk>
