# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	physfs
PORTVERSION=	2.0.3
CATEGORIES=	devel
MASTER_SITES=	http://icculus.org/${PORTNAME}/downloads/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Library to provide abstract access to various archives

CONFLICTS_INSTALL=	physfs-devel-[0-9]*

USES=		cmake tar:bzip2
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|CHECK_INCLUDE_FILE(sys/ucred.h HAVE_UCRED_H|& "-include sys/param.h"|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
