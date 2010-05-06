# New ports collection makefile for:	resynthesizer
# Date created:		05 May 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	resynthesizer
PORTVERSION=	0.16
CATEGORIES=	graphics
MASTER_SITES=	http://www.logarithmic.net/pfh-files/resynthesizer/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	gimp-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Gimp plug-in for texture synthesis

LIB_DEPENDS=	gimp-2.0:${PORTSDIR}/graphics/gimp-app

GIMPTOOL?=	gimptool-2.0
PLUGINS_DIR?=	libexec/gimp/2.2/plug-ins
SCRIPTS_DIR?=	share/gimp/scripts

MAKE_JOBS_SAFE=	yes
PLIST_FILES=	${PLUGINS_DIR}/resynth \
		${SCRIPTS_DIR}/smart-enlarge.scm \
		${SCRIPTS_DIR}/smart-remove.scm

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} \
		`${GIMPTOOL} --cflags --libs` -o resynth resynth.cc

do-install:
	${MKDIR} ${PREFIX}/${PLUGINS_DIR} ${PREFIX}/${SCRIPTS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/resynth ${PREFIX}/${PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/smart-enlarge.scm \
		${WRKSRC}/smart-remove.scm ${PREFIX}/${SCRIPTS_DIR}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
