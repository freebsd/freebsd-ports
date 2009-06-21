# Ports collection Makefile for:	Eficas
# Date created:				Jul 07 2003
# Whom:					thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	eficas
DISTVERSIONPREFIX=	full-src-
DISTVERSION=	1.16.0-1
DISTVERSIONSUFFIX=	.noarch
CATEGORIES=	french cad
MASTER_SITES=	http://www.code-aster.org/V2/UPLOAD/DOC/Telechargement/
DISTNAME=	aster-${DISTVERSIONPREFIX}${ASTER_DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ASter Command FIle Editor

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/py-Pmw		\
		${PYTHON_SITELIBDIR}/mx:${PORTSDIR}/lang/py-mx-base		\
		${PYNUMERIC}							\
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

ASTER_VER=	10.0.3
ASTER_DISTVERSION=	${ASTER_VER}-2
EXTRACT_WRKSRC=	${WRKDIR}/aster-${DISTVERSIONPREFIX}${ASTER_VER}/SRC

USE_PYTHON=	yes
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

LEFICASDIR?=	apps/${PORTNAME}
EFICASDIR=	${PREFIX}/${LEFICASDIR}
PLIST_SUB=	EFICASDIR=${LEFICASDIR} STAV=STA9
SUB_FILES=	eficas
SUB_LIST=	EFICASDIR=${EFICASDIR} PYTHON_CMD=${PYTHON_CMD}

.if defined(LANG) && ${LANG:Mfr*} != ""
EF_LANG=	fr
.else
EF_LANG=	ang
.endif

.if !defined(WITHOUT_QT)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/qt.so:${PORTSDIR}/x11-toolkits/py-qt
SUB_FILES+=	qtEficas
.endif

ENV2PYTHON=	Misc/Cyclops.py Aster/eficas_aster.py convert/Parserv5/Translate.py	\
		Traducteur/traduitV8V9.py Traducteur/traduitV7V8.py Aster/test_eficas.py\
		Aster/qtEficas_aster.py generator/OpenturnsSTD.py	\
		generator/generator_openturns_study.py generator/generator_openturns_wrapper.py
FIXSHTK=	bureau.py cataediteur.py panels.py
FIXSHQT=	qtCommun.py

post-extract:
	(cd ${WRKDIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${EXTRACT_WRKSRC}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS})

pre-configure:
	${RM} ${WRKSRC}/convert/Parserv5/Translate.py.orig
	${RM} -r ${WRKSRC}/Pmw	# Use our ported Pmw
.for FILE in ${ENV2PYTHON}
	${REINPLACE_CMD} -e "s|^#!*./usr/bin/env python|#!${PYTHON_CMD}|"	\
		-e "s|^#!*./bin/env python|#!${PYTHON_CMD}|" ${WRKSRC}/${FILE}
.endfor
.for tk in TK QT
. for FILE in ${FIXSH${tk}}
	${REINPLACE_CMD} -e "s|/usr/bin/sh|/bin/sh|" ${WRKSRC}/Interface${tk}/${FILE}
. endfor
.endfor
	${REINPLACE_CMD} -e "s#lang='fr'#lang='${EF_LANG}'#"			\
		${WRKSRC}/Aster/prefs.py
	${REINPLACE_CMD} -e "s#os.path.join(rep_cata,'..','Doc')#\"${DOCSDIR}\"#"	\
		-e "s#os.path.join(prefs.REPINI,'../Pmw')#'${PYTHON_SITELIBDIR}/Pmw'#"	\
		${WRKSRC}/Aster/editeur.ini

do-install:
	${MKDIR} ${EFICASDIR}
	${CP} -R ${WRKSRC}/* ${EFICASDIR}
	${RMDIR} ${EFICASDIR}/Aster/Doc
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${EFICASDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${EFICASDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/eficas ${PREFIX}/bin
.if !defined(WITHOUT_QT)
	${INSTALL_SCRIPT} ${WRKDIR}/qtEficas ${PREFIX}/bin
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
