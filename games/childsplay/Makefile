# New ports collection makefile for:	pyassetml
# Date created:				6 July 2004
# Whom:					bruno
#
# $FreeBSD$
#

PORTNAME=	childsplay
PORTVERSION=	0.71
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

BROKEN=		Incomplete pkg-plist

USE_PYTHON=	yes
USE_REINPLACE=	yes

# avoid asking for translation to your local language on install
MAKE_ENV=	LANG=C

MAN6=		childsplay.6

post-patch:
	@${REINPLACE_CMD} -e "s@PREFIX = /usr/local@PREFIX=${PREFIX}@g " ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s@ASSETMLROOT = '/usr/local'@ASSETMLROOT= '${PREFIX}'@g " ${WRKSRC}/pyassetml.py
	@${REINPLACE_CMD} -e "s@PREFIX = \"/usr/local\"@PREFIX= '${PREFIX}'@g" ${WRKSRC}/pyassetmlcreator.py
	@${REINPLACE_CMD} -e "s@ASSETMLROOT= '/usr/local'@ASSETMLROOT= '${PREFIX}/share/gnome/assetml'@g" ${WRKSRC}/pyassetmlSDL.py
	@${REINPLACE_CMD} -e "s@PREFIX=/usr/local@PREFIX=${PREFIX}@g " ${WRKSRC}/cleanup.sh
	@${REINPLACE_CMD} -e "s@'/','usr'@'${PREFIX}'@g" ${WRKSRC}/pyassetmlcreator.py
	@${REINPLACE_CMD} -e "s@/usr/share/assetml@${PREFIX}/share/gnome/assetml@g" ${WRKSRC}/pyassetml.py ${WRKSRC}/pyassetmlSDL.py

post-build:
	@${FIND} ${WRKSRC} -name *.orig -delete

.include <bsd.port.mk>
