# New ports collection makefile for:	xmixer
# Date created:		27 October 1999
# Whom:			trevor@jpj.net
#
# $FreeBSD$
#

PORTNAME=	xmixer
PORTVERSION=	0.9.4
CATEGORIES=	audio
MASTER_SITES=	http://www.hdk-berlin.de/~rasca/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_AUTOCONF=	yes

MAN1=		xmixer.1
MLINKS=		xmixer.1 xgmixer.1

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS}  ${REINPLACE_CMD} -e 's|rxvt -e|xterm -e|g'

.include <bsd.port.mk>
