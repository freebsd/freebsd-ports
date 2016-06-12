# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfastjson
PORTVERSION=	0.99.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	libfastjson is a fork from json-c

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	rsyslog

GNU_CONFIGURE=	yes
USES=		autoreconf libtool pkgconfig
INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} -e 's|$(libdir)/pkgconfig|$(libdir)data/pkgconfig|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
