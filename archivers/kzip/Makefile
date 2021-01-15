# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kzip
DISTVERSION=	20200115
CATEGORIES=	archivers
MASTER_SITES=	http://static.jonof.id.au/dl/kenutils/
DISTNAME=	kzipmix-${DISTVERSION}-bsd-static

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	PKZIP-compatible compressor focusing on space over speed

ONLY_FOR_ARCHS=	amd64 i386

LICENSE_PERMS=no-pkg-mirror

NO_CDROM=	License does not allow redistribution
RESTRICTED=	${NO_CDROM}

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

.include <bsd.port.mk>
