# New ports collection makefile for:	TTA encoder
# Date created:				10 Aug 2004
# Whom:			Martin Dieringer <Martin.Dieringer@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	tta
PORTVERSION=	3.4.1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}enc-src
DISTNAME=	${PORTNAME}enc-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	The True Audio Encoder, lossless (de)compressor

PROGRAM=	ttaenc

PORTDOCS=	README
PLIST_FILES=	bin/ttaenc

post-patch:
	@${REINPLACE_CMD} -e '/ifdef _BIG_ENDIAN/s|ifdef|if _BYTE_ORDER ==|' \
		${WRKSRC}/${PROGRAM}.h

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/${PROGRAM} \
		${WRKSRC}/${PROGRAM}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
