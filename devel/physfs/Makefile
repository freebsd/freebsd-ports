# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	physfs
PORTVERSION=	2.0.3
CATEGORIES=	devel
MASTER_SITES=	http://offload1.icculus.org:9090/${PORTNAME}/downloads/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A library to provide abstract access to various archives

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

patch-autotools-libtool:
	@${DO_NADA}

post-patch:
	@${REINPLACE_CMD} -e \
		's|CHECK_INCLUDE_FILE(sys/ucred.h HAVE_UCRED_H|& "-include sys/param.h"|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
