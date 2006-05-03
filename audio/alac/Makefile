# New ports collection makefile for:	alac
# Date created:		2005-03-08
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	alac
PORTVERSION=	0.1.2
CATEGORIES=	audio
MASTER_SITES=	http://crazney.net/programs/itunes/files/
DISTNAME=	${PORTNAME}_decoder-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Basic decoder for Apple Lossless Audio Codec files (ALAC)

WRKSRC=		${WRKDIR}/${PORTNAME}_decoder
ALL_TARGET=	alac

PLIST_FILES=	bin/alac
PORTDOCS=	README

.include <bsd.port.pre.mk>

post-patch:
.if !defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e 's|-ggdb||' \
		${WRKSRC}/${MAKEFILE}
.endif
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/*.*
.endif
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|-O3|${CFLAGS}|' \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alac ${PREFIX}/bin/
.if !defined(WITHOUT_PORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
