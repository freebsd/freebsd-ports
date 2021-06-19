PORTNAME=	simplevaders
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://dusted.dk/pages/simplevaders/ \
		https://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Space-Invaders like 2D space shooter

LICENSE=	GPLv3+

USES=		gl localbase:ldflags sdl tar:bzip2
USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/main.cpp
	@${RM} ${WRKSRC}/data/*\~

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
