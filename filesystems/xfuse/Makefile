PORTNAME=	xfuse
DISTVERSION=	0.5.0
CATEGORIES=	filesystems
MASTER_SITES=	CRATESIO
MASTER_SITE_SUBDIR=	xfs-fuse/${DISTVERSION}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	xfs-fuse-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Read-only FUSE server implementing XFS
WWW=		https://github.com/KhaledEmaraDev/xfuse

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo fuse:3

PLIST_FILES=	bin/xfs-fuse \
		share/man/man1/xfs-fuse.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/xfs-fuse.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
