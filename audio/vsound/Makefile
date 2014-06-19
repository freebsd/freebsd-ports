# Created by: Rahul Siddharthan <rsidd@online.fr>
# $FreeBSD$

PORTNAME=	vsound
PORTVERSION=	0.6
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www.vsound.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for capturing audio streams from programs with OSS output

BUILD_DEPENDS=	sox:${PORTSDIR}/audio/sox
RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox

USES=		libtool
GNU_CONFIGURE=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/vsound/libvsound.so

.include <bsd.port.mk>
