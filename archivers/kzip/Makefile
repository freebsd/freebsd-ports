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

FILES=		kzip-static
.for file in ${FILES}
PLIST_FILES+=	bin/${file:S/-static$//}
.endfor

post-extract:
.for file in ${FILES}
	@${BRANDELF} -t Linux ${WRKSRC}/${file}
.endfor

do-install:
.for file in ${FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin/${file:S/-static$//}
.endfor

.include <bsd.port.mk>
