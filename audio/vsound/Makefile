PORTNAME=	vsound
PORTVERSION=	0.6
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://down1.chinaunix.net/distfiles/ \
		http://freebsd.nsu.ru/distfiles/ GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for capturing audio streams from programs with OSS output

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

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
