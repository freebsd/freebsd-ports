# New ports collection makefile for:	xmpeg3
# Date created:		7 July 1997
# Whom:			doconnor@ist.flinders.edu.au
#
# $FreeBSD$
#

PORTNAME=	xmpeg3
PORTVERSION=	1.0
CATEGORIES=	audio tk82
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/audio/mpeg/amp/
DISTNAME=	xmp3_1.0.0
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple TCL interface to the Amp Mpeg-3 player

RUN_DEPENDS=	amp:${PORTSDIR}/audio/amp \
		wish8.2:${PORTSDIR}/x11-toolkits/tk82

PLIST_FILES=	bin/xmpeg3
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/xmpeg3
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|@@PREFIX@@|${PREFIX}|' ${WRKSRC}/xmpeg3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmpeg3 ${PREFIX}/bin

.include <bsd.port.mk>
