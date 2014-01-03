# Created by: Rahul Siddharthan <rsidd@online.fr>
# $FreeBSD$

PORTNAME=	vsound
PORTVERSION=	0.6
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://www.vsound.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for capturing audio streams from programs with OSS output

BUILD_DEPENDS=	sox:${PORTSDIR}/audio/sox
RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox
NO_STAGE=	yes

USE_AUTOTOOLS=	libtool

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
