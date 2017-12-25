# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kzip
DISTVERSION=	20150319
CATEGORIES=	archivers linux
MASTER_SITES=	http://static.jonof.id.au/dl/kenutils/
DISTNAME=	kzipmix-${DISTVERSION}-linux-static

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PKZIP-compatible compressor focusing on space over speed

NO_CDROM=	License does not allow redistribution
NO_PACKAGE=	${NO_CDROM}
RESTRICTED=	${NO_CDROM}

ONLY_FOR_ARCHS=	amd64 i386

USES=		linux
NO_BUILD=	yes
WRKSRC_SUBDIR=	i686

PLIST_FILES=	bin/kzip

post-extract:
	@${BRANDELF} -t Linux ${WRKSRC}/kzip-static

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kzip-static ${STAGEDIR}${PREFIX}/bin/kzip

.include <bsd.port.mk>
