PORTNAME=	blokish
PORTVERSION=	0.9.4
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Clone of the strategy board game 'Blokus'
WWW=		https://sourceforge.net/projects/blokish/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gl gmake localbase tar:tgz
GNU_CONFIGURE=	yes
USE_GL=		gl
USE_WX=		3.0

MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.xpm

DESKTOP_ENTRIES="Blokish" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;LogicGame;" \
		""

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|' \
		${WRKSRC}/makefile.in ${WRKSRC}/configure
	@${REINPLACE_CMD} '/^LIBS =/s/$$/ -lGL/' ${WRKSRC}/makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
