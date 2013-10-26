# Created by: Craig Leres <leres@ee.lbl.gov>
# $FreeBSD$

PORTNAME=	arduino-glcd
PORTVERSION=	3.20111205
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://glcd-arduino.googlecode.com/files/
DISTNAME=	glcd-20111205

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	GLCD Graphical LCD Library

LICENSE=	LGPL21

RUN_DEPENDS=	arduino:${PORTSDIR}/devel/arduino

WRKSRC=		${WRKDIR}/glcd
USE_ZIP=	yes
USE_DOS2UNIX=	yes

NO_BUILD=	yes
NO_STAGE=	yes

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

do-install:
	${MKDIR} ${PREFIX}/arduino/libraries/glcd
	(cd ${WRKDIR}/glcd && ${COPYTREE_SHARE} "${FILES}" \
	    ${PREFIX}/arduino/libraries/glcd "! -name *\.orig")
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKDIR}/glcd/examples && ${COPYTREE_SHARE} . \
	    ${EXAMPLESDIR} "! -name *\.orig")
.endif

PLIST_SUB+=	EXAMPLESDIR_REL=${EXAMPLESDIR_REL}

.include <bsd.port.mk>
