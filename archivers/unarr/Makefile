# $FreeBSD$

PORTNAME=	unarr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	archivers

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Decompression library for RAR, TAR, ZIP and 7z* archives

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	selmf

post-patch:
.if ${/usr/bin/ld:L:tA} != /usr/bin/ld.lld
	@${REINPLACE_CMD} 's/ -flto//' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
