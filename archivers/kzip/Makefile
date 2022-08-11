PORTNAME=	kzip
DISTVERSION=	20200115
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://static.jonof.id.au/dl/kenutils/
DISTNAME=	kzipmix-${DISTVERSION}-bsd-static

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	PKZIP-compatible compressor focusing on space over speed

LICENSE=	KZIP
LICENSE_NAME=	KZIP License
LICENSE_FILE=	${FILESDIR}/license.txt
LICENSE_PERMS=	pkg-mirror no-dist-sell no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
WRKSRC_SUBDIR=	${ARCH}
.else
WRKSRC_SUBDIR=	i686
.endif

PLIST_FILES=	bin/kzip

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kzip-static ${STAGEDIR}${PREFIX}/bin/kzip

.include <bsd.port.post.mk>
