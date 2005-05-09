# New ports collection makefile for:	kimdaba
# Date created:			Sat Dec 13 16:09:29 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kimdaba
PORTVERSION=		2.1
CATEGORIES=		graphics kde
MASTER_SITES=		http://ktown.kde.org/kimdaba/download/

MAINTAINER=		markus@FreeBSD.org
COMMENT=		Image database for KDE

RUN_DEPENDS=		kipidcrawclient:${PORTSDIR}/graphics/kipi-plugins
BUILD_DEPENDS=		${RUN_DEPENDS}

USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${FIND} ${WRKSRC}/translations -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|LANG)/doc|LANG)/kimdaba|g'

.include <bsd.port.mk>
