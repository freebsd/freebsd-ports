# New ports collection makefile for:	wmusic
# Date created:				16 September 2000
# Whom:					eric
#
# $FreeBSD$
#

PORTNAME=	wmusic
PORTVERSION=	1.4.10
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://home.jtan.com/~john/wmusic/downloads/

MAINTAINER=	eric@FreeBSD.org

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PATH_GTKCONFIG=${GTK_CONFIG}

pre-build:
	cd ${WRKSRC} && make clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/wmusic ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
