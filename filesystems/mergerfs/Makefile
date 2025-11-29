PORTNAME=	mergerfs
DISTVERSION=	2.41.1
PORTREVISION=	1
CATEGORIES=	filesystems
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Featureful FUSE based union filesystem
WWW=		https://github.com/trapexit/mergerfs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fuse gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	trapexit

PLIST_FILES=	bin/fsck.mergerfs \
		bin/mergerfs \
		bin/mergerfs.collect-info \
		lib/mergerfs/preload.so \
		share/man/man1/mergerfs.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mergerfs \
		${STAGEDIR}${PREFIX}/lib/mergerfs/preload.so

.include <bsd.port.mk>
