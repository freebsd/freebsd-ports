PORTNAME=	arduino-openglcd
DISTVERSION=	1.0rc3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/bperrybap/openglcd/downloads/
DISTNAME=	openGLCD-v${DISTVERSION}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	GLCD Graphical LCD Library

LICENSE=	GPLv3

RUN_DEPENDS=	arduino>=1.0.6:devel/arduino

WRKSRC=		${WRKDIR}/openGLCD
USES=		zip dos2unix

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

FILES=	\
	Buildinfo.txt \
	ChangeLog.txt \
	License.txt \
	gText.cpp \
	glcd.cpp \
	glcd.h.compat \
	glcd_Device.cpp \
	keywords.txt \
	library.properties \
	openGLCD.h \
	openGLCD_Buildinfo.h \
	openGLCD_Config.h \
	readme.txt

DIRS=	\
	GPLdocs \
	bitmaps \
	config \
	device \
	fonts \
	include

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/arduino/libraries/glcd
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${FILES}" \
	    ${STAGEDIR}${PREFIX}/arduino/libraries/glcd "! -name *\.orig")
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${DIRS}" \
	    ${STAGEDIR}${PREFIX}/arduino/libraries/glcd)
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${DOCSDIR} "! -name *\.orig")
do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${EXAMPLESDIR} "! -name *\.orig")

.include <bsd.port.mk>
