# New ports collection makefile for:	he2
# Date created:				3 August 2001
# Whom:					nadav@libagent.org
#
# $FreeBSD$
#

PORTNAME=	he2
PORTVERSION=	0.61
CATEGORIES=	hebrew editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nadav@libagent.org

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/hebrew:${PORTSDIR}/hebrew/elmar-fonts

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
