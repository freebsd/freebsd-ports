# New Ports collection makefile for:	kye-data
# Date created:		25 July 2012
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	kye-data
PORTVERSION=	20120725
CATEGORIES=	games
MASTER_SITES=	http://games.moria.org.uk/kye/ \
		http://www.nuke.demon.co.uk/kye/levels/
# Selection of production-ready/well-known Kye Levels
# (ziped Levels already included from games.moria.org.uk are excluded)
# Please contact the MAINTAINER if a Level is missing
DISTFILES=	${LEVELS} ${LEVELS_KYE:S/$/.zip/}
DIST_SUBDIR=	kye
EXTRACT_ONLY=	#empty

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Original extra Levels for Python Kye

RUN_DEPENDS=	Kye:${PORTSDIR}/games/kye
EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SHAREMODE=	0644

DATADIR=	${PREFIX}/share/kye
LEVELS=		jungle.kye maze.kye problem.kye system.kye mystical.kye \
		hordes.kye crowds.kye
LEVELS_KYE=	vvv1 vvv2 vvv3 vexkyelevels Training \
		Beginner RComb 2Fun4Me Action2 jg \
		afebrile alanskye AntKye2 Danish Garyskye \
		gsmick InARush nelsons Newkye philsel1 \
		Ricardo TPsKye sampler

post-extract-script:
.  for f in ${LEVELS_KYE:S/$/.zip/}
	@${UNZIP_CMD} -qo -d ${WRKDIR} ${DISTDIR}/${DIST_SUBDIR}/${f}
.  endfor
	@for i in `${FIND} ${WRKDIR} -name \*.KYE`; do \
		${MV} $$i `echo $$i | ${SED} -e 's/KYE/kye/'`; done

do-install:
.  for f in ${LEVELS}
	@cd ${DISTDIR}/${DIST_SUBDIR} && ${COPYTREE_SHARE} ${f} ${DATADIR}
.  endfor
	@cd ${WRKDIR} && ${COPYTREE_SHARE} \*.kye ${DATADIR}

post-install:
	@${INSTALL_DATA} ${WRKDIR}/"newkye_ french_engl.rtf" ${DATADIR}/Newkye_french_engl.rtf
	@${INSTALL_DATA} ${WRKDIR}/readme.txt ${DATADIR}/vex.txt
	@${INSTALL_DATA} ${WRKDIR}/Readit.txt ${DATADIR}/TPsKye.txt
	@${INSTALL_DATA} ${WRKDIR}/Readme.txt ${DATADIR}/Training.txt

.include <bsd.port.mk>
