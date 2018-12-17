# Created by: stas
# $FreeBSD$

PORTNAME=	libinotify
PORTVERSION=	20180201
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Kevent based inotify compatible library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		autoreconf libtool

GH_ACCOUNT=	${PORTNAME}-kqueue
GH_PROJECT=	${PORTNAME}-kqueue
USE_GITHUB=	yes

.include <bsd.port.mk>
