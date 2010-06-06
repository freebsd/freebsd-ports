# New ports collection makefile for:	blackshadeselite
# Date created:		27 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	blackshadeselite
PORTVERSION=	0.0.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/blackshadeselite/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Psychic Bodyguard FPS - protect the VIP

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GL=		yes
USE_OPENAL=	al alut

MAKE_ARGS=	CC=${CC} CXX=${CXX}

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	Readme Readme.elite

post-patch:
	@${REINPLACE_CMD} -e '/InitGL/ s|.*|chdir("${DATADIR}"); &|' ${WRKSRC}/Source/Main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objs/blackshades ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} Data ${DATADIR}/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
