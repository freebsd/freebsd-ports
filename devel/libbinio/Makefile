# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	libbinio
PORTVERSION=	1.5
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	devel

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Binary I/O stream class library

LICENSE=	LGPL21

USES=		autoreconf compiler:c11 libtool pathfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

GH_ACCOUNT=	adplug

INSTALL_TARGET=	install-strip

PORTSCOUT=	skipv:start

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS\ =\).*|\1 src|' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
