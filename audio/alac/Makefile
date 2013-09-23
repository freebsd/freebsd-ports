# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alac
PORTVERSION=	0.2.0
CATEGORIES=	audio
MASTER_SITES=	http://craz.net/programs/itunes/files/
DISTNAME=	${PORTNAME}_decoder-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Basic decoder for Apple Lossless Audio Codec files (ALAC)

WRKSRC=		${WRKDIR}/${PORTNAME}_decoder
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	alac

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/alac
PORTDOCS=	README

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alac ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
