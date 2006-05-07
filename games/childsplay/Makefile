# New ports collection makefile for:	pyassetml
# Date created:				6 July 2004
# Whom:					bruno
#
# $FreeBSD$
#

PORTNAME=	childsplay
PORTVERSION=	0.80.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	childsplay
EXTRACT_SUFX=	.tgz

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	Educative games for children

BUILD_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/pygame/pygame.h:${PORTSDIR}/devel/py-game
RUN_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/pygame/pygame.h:${PORTSDIR}/devel/py-game
LIB_DEPENDS=	assetml.0:${PORTSDIR}/devel/libassetml

USE_PYTHON=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes

# avoid asking for translation to your local language on install
MAKE_ENV=	LANG=C

MAN6=		childsplay.6 letters-trans.6
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e "s@PREFIX=/usr/local@PREFIX=${PREFIX}@g " ${WRKSRC}/INSTALL.sh
	@${REINPLACE_CMD} -e "s@ASSETMLROOT = '/usr/local@ASSETMLROOT= '${PREFIX}@g" ${WRKSRC}/pyassetml.py
	@${REINPLACE_CMD} -e "s@PREFIX=/usr/local@PREFIX=${PREFIX}@g" ${WRKSRC}/cleanup.sh
	@${REINPLACE_CMD} -e "s@/usr/local/lib/games@${PREFIX}@g" ${WRKSRC}/childsplay.sh

post-build:
	@${FIND} ${WRKSRC} -name *.orig -delete

.include <bsd.port.mk>
