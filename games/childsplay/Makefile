# Created by: bruno
# $FreeBSD$

PORTNAME=	childsplay
PORTVERSION=	0.90.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Educative games for children

BUILD_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/pygame/pygame.h:${PORTSDIR}/devel/py-game
RUN_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/pygame/pygame.h:${PORTSDIR}/devel/py-game
LIB_DEPENDS=	assetml.0:${PORTSDIR}/devel/libassetml

USES=		shebangfix
USE_PYTHON=	2
NO_BUILD=	yes

python_OLD_CMD=	/usr/bin/env python
python_CMD=	/usr/bin/env python2
SHEBANG_FILES=	childsplay.py

# avoid asking for translation to your local language on install
MAKE_ENV=	LANG=C

MAN6=		childsplay.6 letters-trans.6
MANCOMPRESSED=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s@PREFIX=/usr/local@PREFIX=${PREFIX}@g " ${WRKSRC}/INSTALL.sh
	@${REINPLACE_CMD} -e "s@ASSETMLROOT = '/usr/local@ASSETMLROOT= '${PREFIX}@g" ${WRKSRC}/pyassetml.py
	@${REINPLACE_CMD} -e "s@PREFIX=/usr/local@PREFIX=${PREFIX}@g" ${WRKSRC}/cleanup.sh
	@${REINPLACE_CMD} -e "s@/usr/local/lib/games@${PREFIX}@g" ${WRKSRC}/childsplay.sh

post-build:
	@${FIND} ${WRKSRC} -name *.orig -delete

.include <bsd.port.mk>
