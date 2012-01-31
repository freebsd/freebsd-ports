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

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	The True Audio Encoder, lossless (de)compressor

LICENSE=	GPLv2

USE_GMAKE=	yes
ALL_TARGET=	ttaenc
MAKE_ARGS=	CFLAGS="${CFLAGS}" INSDIR="${PREFIX}/bin"

PLIST_FILES=	bin/ttaenc
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e '/ifdef _BIG_ENDIAN/s|ifdef|if _BYTE_ORDER ==|' \
		${WRKSRC}/ttaenc.h
	@${REINPLACE_CMD} -e 's|gcc|${CC}| ; /strip/d ; \
		s|install -m 755|${INSTALL_PROGRAM}|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
