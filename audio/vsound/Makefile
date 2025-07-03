PORTNAME=	vsound
PORTVERSION=	0.6
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://download.nus.edu.sg/mirror/gentoo/distfiles/65/ \
		http://freebsd.nsu.ru/distfiles/ LOCAL/danfe

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Utility for capturing audio streams from programs with OSS output
WWW=		http://web.archive.org/web/20210502033331/http://www.vsound.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

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
