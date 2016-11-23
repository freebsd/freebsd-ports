# $FreeBSD$

PORTNAME=	npth
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	GNUPG/${PORTNAME}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	New GNU Portable Threads

LICENSE=	LGPL3 GPLv2
LICENSE_COMB=	dual

USES=		tar:bzip2 libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
LIBS=		-lpthread
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
