# Created by: Rahul Siddharthan <rsidd@online.fr>
# $FreeBSD$

PORTNAME=	vsound
PORTVERSION=	0.6
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www.vsound.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for capturing audio streams from programs with OSS output

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	sox:audio/sox
RUN_DEPENDS=	sox:audio/sox

USES=		alias libtool
GNU_CONFIGURE=	yes

BROKEN_aarch64=	Fails to build: error: Cannot determine endian-ness of processor

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/vsound/libvsound.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
