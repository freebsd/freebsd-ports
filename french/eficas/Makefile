# Ports collection Makefile for:	Eficas
# Date created:				Jul 07 2003
# Whom:					thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	Eficas
PORTVERSION=	1.5
CATEGORIES=	french cad python
MASTER_SITES=	http://www.code-aster.org/FICHIERS/eficas/
DISTNAME=	${PORTNAME}V${PORTVERSION:C/\./_/}b3AsterSTA7

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ASter Command FIle Editor

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/pmw		\
		${PYTHON_SITELIBDIR}/mx:${PORTSDIR}/lang/py-mx-base		\
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

.if !defined(NOPORTDOCS)
RUN_DEPENDS+=	acroread:${PORTSDIR}/print/acroread5
.endif

USE_PYTHON=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes

LEFICASDIR?=	apps/${PORTNAME}
EFICASDIR=	${PREFIX}/${LEFICASDIR}
PLIST_SUB=	EFICASDIR=${LEFICASDIR}

.if defined(LANG) && ${LANG:Mfr*} != ""
EF_LANG=	fr
.else
EF_LANG=	ang
.endif

ENV2PYTHON=	Misc/Cyclops.py Aster/eficas_aster.py convert/Parserv5/Translate.py

post-patch:
.for FILE in ${ENV2PYTHON}
	@${REINPLACE_CMD} -e "s|^#!*./usr/bin/env python|#!${PYTHON_CMD}|"	\
		${WRKSRC}/${FILE}
.endfor
	@${REINPLACE_CMD} -e "s#lang='fr'#lang='${EF_LANG}'#"			\
		${WRKSRC}/Aster/prefs.py
	@${REINPLACE_CMD} -e "s#/usr/bin/acroread#${LOCALBASE}/bin/acroread#"	\
			-e "s#os.path.join(rep_cata,'..','Doc')#\"${DOCSDIR}\"#"	\
		${WRKSRC}/Aster/editeur.ini

pre-install:
.if defined(NOPORTDOCS)
	@${RM} -rf ${WRKSRC}/Aster/Doc
.endif
	@${FIND} ${WRKDIR} -type f -exec ${CHMOD} ${SHAREMODE} \{\} \;

do-install:
	@${MKDIR} ${EFICASDIR}
	@${CP} -R ${WRKSRC}/* ${EFICASDIR}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${EFICASDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${EFICASDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EFICASDIR}
	@${CP} ${FILESDIR}/eficas ${WRKDIR}
	@${REINPLACE_CMD} -e "s#%%EFICASDIR%%#${EFICASDIR}#"		\
		-e "s#%%PYTHON_CMD%%#${PYTHON_CMD}#" ${WRKDIR}/eficas
	@${INSTALL_SCRIPT} ${WRKDIR}/eficas ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MV} ${EFICASDIR}/Aster/Doc/* ${DOCSDIR}
	@${RMDIR} ${EFICASDIR}/Aster/Doc
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
