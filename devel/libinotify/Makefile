# Created by: stas
# $FreeBSD$

PORTNAME=	libinotify
PORTVERSION=	20180201
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Kevent based inotify compatible library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf libtool

USE_GITHUB=	yes
GH_ACCOUNT=	libinotify-kqueue
GH_PROJECT=	libinotify-kqueue

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-skip-subfiles=smbfs,fusefs
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
