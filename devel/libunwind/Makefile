# Created by: stas@FreeBSD.org
# $FreeBSD$

PORTNAME=	libunwind
PORTVERSION=	20170113	# This is the release date of libunwind 1.2
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH
DISTNAME=	${PORTNAME}-1.2

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Generic stack unwinding library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386 amd64

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-documentation
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig

PLIST_SUB=	ARCH=${ARCH:S|i386|x86|:S|amd64|x86_64|}

.include <bsd.port.mk>
