PORTNAME=	vsound
PORTVERSION=	0.6
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://down1.chinaunix.net/distfiles/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for capturing audio streams from programs with OSS output
WWW=		http://www.vsound.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Upstream disappeared
EXPIRATION_DATE=2025-01-27

BROKEN_riscv64=		fails to compile: vsound.c:101:4: Endian guess seems incorrect.

BUILD_DEPENDS=	sox:audio/sox
RUN_DEPENDS=	sox:audio/sox

USES=		alias libtool

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/vsound/libvsound.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
