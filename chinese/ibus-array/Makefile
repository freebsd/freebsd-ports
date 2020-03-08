# $FreeBSD$

PORTNAME=	ibus-array
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	release-
CATEGORIES=	chinese

MAINTAINER=	jiashiun@gmail.com
COMMENT=	Array 30 input method for IBus

LICENSE=	GPLv2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	ibus-daemon:textproc/ibus
RUN_DEPENDS=	ibus-daemon:textproc/ibus

GNU_CONFIGURE=	yes

USES=		autoreconf gettext gmake gnome libtool pkgconfig python:2.7 \
		sqlite
USE_GNOME+=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	lexical

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
