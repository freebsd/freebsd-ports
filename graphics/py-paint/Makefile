# New ports collection makefile for:	py-paint
# Date created:				8 July 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	paint
PORTVERSION=	0.1
CATEGORIES=	graphics python
MASTER_SITES=	http://object-craft.com.au/projects/paint/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@fallin.lv

BUILD_DEPENDS=	${PYDISTUTILS}
LIB_DEPENDS=	ttf.4:${PORTSDIR}/print/freetype \
		png.5:${PORTSDIR}/graphics/png \
		art_lgpl.5:${PORTSDIR}/graphics/libart

USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g} \
		SHARE_SUBDIR=${SHARE_SUBDIR}
WRKSRC=		${WRKDIR}/${PORTNAME}
SHARE_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
PYDIST_SETUP=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

INC_DIRS=	["${LOCALBASE}/include","${X11BASE}/include","${LOCALBASE}/include/freetype"]
LIB_DIRS=	["${LOCALBASE}/lib","${X11BASE}/lib"]
REPATCH=	cd ${WRKSRC} && ${SED}
REPATCHSUBST=	-e 's@^\(.*libraries.*\)$$@\1include_dirs=${INC_DIRS},library_dirs=${LIB_DIRS},@g'
REPATCHFILES=	setup.py
TMPSUFFIX=	.temp
EXAMPLES=	test_bar.py test_paint.py testpie.py

.include <bsd.port.pre.mk>

post-patch:
.if ${PYTHON_REL} >= 160
	cd ${WRKSRC} && ${PATCH} -s <${PATCHDIR}/optpatch-aa
.endif
.for file in ${REPATCHFILES}
	${REPATCH} ${REPATCHSUBST} ${file} > ${file}${TMPSUFFIX} && \
		${CAT} ${file}${TMPSUFFIX} > ${file}
.endfor

do-build:
	${PYDIST_SETUP} build

do-install:
	${PYDIST_SETUP} install
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/${SHARE_SUBDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${PREFIX}/share/examples/${SHARE_SUBDIR}
.endif

.include <bsd.port.post.mk>
