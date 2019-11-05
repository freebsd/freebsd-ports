# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	slune
PORTVERSION=	1.0.16
CATEGORIES=	games python
MASTER_SITES=	CHEESESHOP
DISTNAME=	Slune-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D racing game with car-crashing and lots of action

LICENSE=	GPLv2

LIB_DEPENDS=	libcal3d.so:graphics/cal3d
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openal>0:audio/py-openal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vorbis>0:audio/py-vorbis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soya3d>0:graphics/py-soya3d@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py2play>0:net-p2p/py-py2play@${PY_FLAVOR}

USES=		dos2unix gettext gl python:2.7 sdl

DOS2UNIX_GLOB=	*.po *.mo
USE_GL=		glew
USE_SDL=	sdl mixer
USE_PYTHON=	autoplist distutils

PYDISTUTILS_PKGNAME=	Slune
PYDISTUTILS_EGGINFODIR=	${PREFIX}/share

PLIST_FILES=	man/man6/slune.6.gz

PORTDOCS=	README

DESKTOP_ENTRIES=	"Slune" \
			"3D racing game" \
			"${DATADIR}/images/slune.48.png" \
			"slune" \
			"Game;ArcadeGame;" \
			false

OPTIONS_DEFINE=	DOCS

post-extract:
	${RM} ${WRKSRC}/locale/es/LC_MESSAGES/slune.po.*
	${RM} ${WRKSRC}/locale/sl/LC_MESSAGES/slune.sl.*
	${RM} ${WRKSRC}/locale/sl/LC_MESSAGES/slune2.*
	${RM} ${WRKSRC}/locale/sl/LC_MESSAGES/slune.po-0

post-patch:
	@${REINPLACE_CMD} -e \
		'/install-purelib/s|=.*|= ${PREFIX}/share| ; \
		 /install-scripts/s|=.*|= ${PREFIX}/bin| ; \
		 /install-data/s|=.*|= ${PREFIX}/share|' ${WRKSRC}/setup.cfg
	@${REINPLACE_CMD} -e \
		'/LC_MESSAGES/s|".",||' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e \
		'/VERSION/s,1.0.15,${PORTVERSION},' ${WRKSRC}/globdef.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	${INSTALL_MAN} ${WRKSRC}/manpage/man6/slune.6 ${STAGEDIR}${MANPREFIX}/man/man6

.include <bsd.port.mk>
