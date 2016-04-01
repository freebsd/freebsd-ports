# Created by: Craig Leres <leres@ee.lbl.gov>
# $FreeBSD$

PORTNAME=	arduino-glcd
PORTVERSION=	3.20111205
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://glcd-arduino.googlecode.com/files/
DISTNAME=	glcd-20111205

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	GLCD Graphical LCD Library

LICENSE=	LGPL21

RUN_DEPENDS=	arduino:devel/arduino

WRKSRC=		${WRKDIR}/glcd
USES=		zip dos2unix

NO_BUILD=	yes

OPTIONS_DEFINE=	EXAMPLES

FILES=	\
	Buildinfo.txt \
	License.txt \
	bitmaps \
	config \
	device \
	doc \
	fonts \
	gText.cpp \
	glcd.cpp \
	glcd.h \
	glcd_Buildinfo.h \
	glcd_Config.h \
	glcd_Device.cpp \
	include \
	readme.txt

PLIST_SUB+=	EXAMPLESDIR_REL=${EXAMPLESDIR_REL}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/arduino/libraries/glcd
	(cd ${WRKDIR}/glcd && ${COPYTREE_SHARE} "${FILES}" \
	    ${STAGEDIR}${PREFIX}/arduino/libraries/glcd "! -name *\.orig")
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKDIR}/glcd/examples && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${EXAMPLESDIR} "! -name *\.orig")

.include <bsd.port.mk>
