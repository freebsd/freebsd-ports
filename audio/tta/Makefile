PORTNAME=	tta
PORTVERSION=	3.4.1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}enc-src
DISTNAME=	${PORTNAME}enc-${PORTVERSION}-src

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	The True Audio Encoder, lossless (de)compressor

LICENSE=	GPLv2

USES=		gmake tar:tgz
ALL_TARGET=	ttaenc
MAKE_ARGS=	CFLAGS="${CFLAGS}" INSDIR="${STAGEDIR}${PREFIX}/bin"

PLIST_FILES=	bin/ttaenc
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/ifdef _BIG_ENDIAN/s|ifdef|if _BYTE_ORDER ==|' \
		${WRKSRC}/ttaenc.h
	@${REINPLACE_CMD} -e 's|__inline void|static &|' ${WRKSRC}/ttaenc.c
	@${REINPLACE_CMD} -e 's|gcc|${CC}| ; /strip/d ; \
		s|install -m 755|${INSTALL_PROGRAM}|' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
