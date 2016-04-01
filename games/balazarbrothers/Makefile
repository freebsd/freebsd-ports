# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	balazarbrothers
PORTVERSION=	0.3.1
PORTREVISION=	7
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/${PORTNAME:S/brothers//}/
DISTNAME=	${PORTNAME:S/b/B/g}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free software 3D puzzle game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcal3d.so:graphics/cal3d \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vorbis>0:audio/py-vorbis \
		${PYTHON_PKGNAMEPREFIX}soya3d>0:graphics/py-soya3d \
		${PYTHON_PKGNAMEPREFIX}tofu>0:net/py-tofu \
		${PYTHON_PKGNAMEPREFIX}cerealizer>0:security/py-cerealizer

NO_ARCH=	yes

USES=		gettext python tar:bzip2 twisted
USE_GL=		glew
USE_PYTHON=	autoplist distutils

PYDISTUTILS_PKGNAME=	BalazarBrothers
PYDISTUTILS_EGGINFODIR=	${PREFIX}/share
PYDISTUTILS_SETUP=	${PYSETUP}
PYDISTUTILS_INSTALLNOSINGLE=	yes

DESKTOP_ENTRIES="BalazarBrothers" "" "" "balazarbrothers" "" ""

OPTIONS_DEFINE=		OPENAL
OPTIONS_DEFAULT=	OPENAL

OPENAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openal>0:audio/py-openal

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install-purelib/s|=.*|= ${PREFIX}/share| ; \
		 /^install-scripts/s|=.*|= ${PREFIX}/bin| ; \
		 /^install-data/s|=.*|= ${PREFIX}/share|' ${WRKSRC}/setup.cfg
	@${REINPLACE_CMD} -e \
		'/LC_MESSAGES/s|".",||' ${WRKSRC}/setup.py

.include <bsd.port.mk>
