PORTNAME=	zerofs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.2
CATEGORIES=	filesystems sysutils

MAINTAINER=	stephan@lichtenauer.co.za
COMMENT=	ZeroFS is 9P/NFS/NBD on top of S3
WWW=		https://github.com/Barre/ZeroFS

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC:H}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	32-bit compilation is not supported

USES=		cargo gmake

USE_GITHUB=	yes
GH_ACCOUNT=	Barre
GH_PROJECT=	ZeroFS

WRKSRC_SUBDIR=	zerofs

PLIST_FILES=	bin/zerofs

.include <bsd.port.mk>
