# New ports collection makefile for:	FTJam
# Date created:		Wed Oct 12 03:26:39 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ftjam
PORTVERSION=	2.5.2
CATEGORIES=	devel
MASTER_SITES=	SF/freetype/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small build tool that can be used as a replacement for make(1)

CONFLICTS=	jam-[0-9]*

USE_BZIP2=	yes
USE_GMAKE=	yes

.ifndef(NOPORTDOCS)
PORTDOCS=	\
		Jam.html \
		Jambase.html \
		Jamfile.html \
		Porting \
		README \
		RELNOTES \
		jam.c
.endif

PLIST_FILES=	bin/${PORTNAME}

do-configure:
	@${REINPLACE_CMD} -E \
		-e 's|^(CC[[:space:]]*=).*$$|\1${CC}|' \
		-e 's|^(CFLAGS[[:space:]]*=).*$$|\1${CFLAGS}|' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
. endfor
.endif
# INSTALL_WRKSRC changes depending on ARCH
	@${INSTALL_PROGRAM} `${FIND} ${WRKSRC} -name "bin.unix*"`/jam \
		${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
