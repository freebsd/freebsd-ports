# New ports collection makefile for:	kzip
# Date created:		Thu Jan 8 2009 14:06:34 UTC
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kzip
DISTVERSION=	20070805
CATEGORIES=	archivers linux
MASTER_SITES=	http://static.jonof.id.au.nyud.net/dl/kenutils/
DISTNAME=	kzipmix-${DISTVERSION}-linux-static

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	PKZIP-compatible compressor focusing on space over speed

NO_CDROM=	License does not allow redistribution
NO_PACKAGE=	${NO_CDROM}
RESTRICTED=	${NO_CDROM}

ONLY_FOR_ARCHS=	i386

USE_LINUX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/kzipmix-static

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
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin/${file:S/-static$//}
.endfor

.include <bsd.port.mk>
