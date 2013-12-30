# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	blackshadeselite
PORTVERSION=	0.0.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/blackshadeselite/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Psychic Bodyguard FPS - protect the VIP

LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis

USES=		gmake openal:al,alut
USE_BZIP2=	yes
USE_SDL=	sdl
USE_GL=		yes

MAKE_ARGS=	CC=${CC} CXX=${CXX}

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/blackshades
PORTDOCS=	Readme Readme.elite
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${FIND} ${WRKSRC}/Data -name '._*' -delete

post-patch:
	@${REINPLACE_CMD} -e '/InitGL/ s|.*|chdir("${DATADIR}"); &|' ${WRKSRC}/Source/Main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objs/blackshades ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} Data ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
