# Created by: Horance Chou <horance@freedom.ie.cycu.edu.tw>
# $FreeBSD$

PORTNAME=	libffi
PORTVERSION=	3.2.1
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/${PORTNAME}
PKGNAMESUFFIX=	321

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Foreign Function Interface (stripped down compat version)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib/compat \
		--disable-static

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
