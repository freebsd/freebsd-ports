# New ports collection makefile for:	py-paint
# Date created:				8 July 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	paint
PORTVERSION=	0.2
CATEGORIES=	graphics python
MASTER_SITES=	http://object-craft.com.au/projects/paint/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		art_lgpl.5:${PORTSDIR}/graphics/libart

USE_FREETYPE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g} \
		SHARE_SUBDIR=${SHARE_SUBDIR}
SHARE_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

INC_DIRS=	["${LOCALBASE}/include/freetype1","${LOCALBASE}/include", \
		 "${X11BASE}/include","${LOCALBASE}/include/freetype1/freetype"]
LIB_DIRS=	["${LOCALBASE}/lib","${X11BASE}/lib"]
TMPSUFFIX=	.temp
EXAMPLES=	test_bar.py test_paint.py testpie.py

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's@^\(.*libraries.*\)$$@\1include_dirs=${INC_DIRS},\
		library_dirs=${LIB_DIRS},@g' ${WRKSRC}/setup.py

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/examples/${SHARE_SUBDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${PREFIX}/share/examples/${SHARE_SUBDIR}
.endif

.include <bsd.port.post.mk>
