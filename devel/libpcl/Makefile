# $FreeBSD$

PORTNAME=	libpcl
DISTVERSION=	1.12
CATEGORIES=	devel
MASTER_SITES=	http://xmailserver.org/
DISTNAME=	pcl-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Portable Coroutine Library for low level functionality for coroutines

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes

PLIST_FILES=	include/pcl.h \
		lib/libpcl.so \
		lib/libpcl.so.1 \
		lib/libpcl.so.1.0.11 \
		man/man3/pcl.3.gz

.include <bsd.port.mk>
