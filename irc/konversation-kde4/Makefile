# New ports collection makefile for:	konversation
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	konversation
PORTVERSION=	0.16
CATEGORIES=	irc kde
MASTER_SITES=	http://download.berlios.de/${PORTNAME}/ \
		http://www.hitnet.rwth-aachen.de/~brueffer/distfiles/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	A user friendly IRC client for KDE

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
