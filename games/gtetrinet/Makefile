# New ports collection makefile for:	gtetrinet
# Date created:				27 Feb 2000
# Whom:					Dan Papasian <bugg@bugg.strangled.net>
#
# $FreeBSD$

PORTNAME=	gtetrinet
PORTVERSION=	0.4.1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtetrinet

MAINTAINER=	bugg@bugg.strangled.net

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes

pre-patch:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g'

.include <bsd.port.mk>
