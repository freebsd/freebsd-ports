# New ports collection makefile for:	linux-vsound
# Date created:				13 June 2002
# Whom:					Rahul Siddharthan <rsidd@online.fr>
#
# $FreeBSD$
#

PORTNAME=	vsound
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.zorg.org/vsound/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for capturing audio streams from programs with OSS output

BUILD_DEPENDS=	sox:${PORTSDIR}/audio/sox
RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox

GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
