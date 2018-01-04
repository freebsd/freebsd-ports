# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	slune
PORTVERSION=	1.0.15
PORTREVISION=	9
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/slune/
DISTNAME=	Slune-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D game. includes racing, car-crashing, and lots of action

LICENSE=	GPLv2

LIB_DEPENDS=	libcal3d.so:graphics/cal3d
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openal>0:audio/py-openal@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vorbis>0:audio/py-vorbis@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soya3d>0:graphics/py-soya3d@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py2play>0:net-p2p/py-py2play@${FLAVOR}

USES=		dos2unix gettext python:2.7 tar:bzip2
DOS2UNIX_GLOB=	*.po *.mo
USE_GL=		glew
USE_SDL=	sdl mixer
USE_PYTHON=	autoplist distutils

PYDISTUTILS_PKGNAME=	Slune
PYDISTUTILS_EGGINFODIR=	${PREFIX}/share

PORTDOCS=	README

DESKTOP_ENTRIES=	"Slune" \
			"3D racing game" \
			"${DATADIR}/images/slune.48.png" \
			"slune" \
			"Game;ArcadeGame;" \
			false

OPTIONS_DEFINE=	DOCS

post-extract:
.for FILE in slune.po.orig slune.po.rej
	@${RM} ${WRKSRC}/locale/es/LC_MESSAGES/${FILE}
.endfor

.for FILE in slune.po-0 slune.sl.mo slune.sl.po slune2.mo slune2.po
	@${RM} ${WRKSRC}/locale/sl/LC_MESSAGES/${FILE}
.endfor

post-patch:
	@${REINPLACE_CMD} -e \
		'/install-purelib/s|=.*|= ${PREFIX}/share| ; \
		 /install-scripts/s|=.*|= ${PREFIX}/lib| ; \
		 /install-data/s|=.*|= ${PREFIX}/share|' ${WRKSRC}/setup.cfg
	@${REINPLACE_CMD} -e \
		'/LC_MESSAGES/s|".",||' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
