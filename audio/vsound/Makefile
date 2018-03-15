# Created by: Rahul Siddharthan <rsidd@online.fr>
# $FreeBSD$

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

NOT_FOR_ARCHS=		aarch64 armv6 armv7
NOT_FOR_ARCHS_REASON=	fails to build: error: Cannot determine endian-ness of processor

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
