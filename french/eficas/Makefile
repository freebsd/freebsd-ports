# Ports collection Makefile for:	Eficas
# Date created:				Jul 07 2003
# Whom:					thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	eficas
DISTVERSION=	1.9.2-1
CATEGORIES=	french cad python
MASTER_SITES=	http://www.code-aster.org/FICHIERS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ASter Command FIle Editor

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/pmw		\
		${PYTHON_SITELIBDIR}/mx:${PORTSDIR}/lang/py-mx-base		\
		${PYNUMERIC}							\
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

LEFICASDIR?=	apps/${PORTNAME}
EFICASDIR=	${PREFIX}/${LEFICASDIR}
PLIST_SUB=	EFICASDIR=${LEFICASDIR} STAV=STA8
SUB_FILES=	eficas
SUB_LIST=	EFICASDIR=${EFICASDIR} PYTHON_CMD=${PYTHON_CMD}

.if defined(LANG) && ${LANG:Mfr*} != ""
EF_LANG=	fr
.else
EF_LANG=	ang
.endif

ENV2PYTHON=	Misc/Cyclops.py Aster/eficas_aster.py convert/Parserv5/Translate.py

post-extract:
	@${MV} ${WRKSRC}/Aster/Doc ${WRKDIR}

pre-configure:
	@${RM} ${WRKSRC}/convert/Parserv5/Translate.py.orig	\
		${WRKSRC}/Editeur/bureau.py.orig
	@${RM} -r ${WRKSRC}/Pmw	# Use our ported Pmw
.for FILE in ${ENV2PYTHON}
	@${REINPLACE_CMD} -e "s|^#!*./usr/bin/env python|#!${PYTHON_CMD}|"	\
		-e "s|^#!*./bin/env python|#!${PYTHON_CMD}|" ${WRKSRC}/${FILE}
.endfor
	@${REINPLACE_CMD} -e "s#lang='fr'#lang='${EF_LANG}'#"			\
		${WRKSRC}/Aster/prefs.py
	@${REINPLACE_CMD} -e "s#os.path.join(rep_cata,'..','Doc')#\"${DOCSDIR}\"#"	\
		-e "s#os.path.join(prefs.REPINI,'../Pmw')#'${PYTHON_SITELIBDIR}/Pmw'#"	\
		${WRKSRC}/Aster/editeur.ini

do-install:
	@${MKDIR} ${EFICASDIR}
	@${CP} -R ${WRKSRC}/* ${EFICASDIR}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${EFICASDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${EFICASDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/eficas ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} ${WRKDIR}/Doc/* ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
