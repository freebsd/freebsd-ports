# Ports collection Makefile for:	Eficas
# Date created:				Jul 07 2003
# Whom:					thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	eficas
DISTVERSION=	2.1.1-1
PORTREVISION=	1
CATEGORIES=	french cad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ASter Command FIle Editor

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/py-Pmw	\
		${PYTHON_SITELIBDIR}/mx:${PORTSDIR}/lang/py-mx-base		\
		${PYNUMPY}							\
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

LEFICASDIR?=	apps/${PORTNAME}
EFICASDIR=	${PREFIX}/${LEFICASDIR}
PLIST_SUB=	EFICASDIR=${LEFICASDIR}
SUB_FILES=	eficas
SUB_LIST=	EFICASDIR=${EFICASDIR} PYTHON_CMD=${PYTHON_CMD}

.if defined(LANG) && ${LANG:Mfr*} != ""
EF_LANG=	fr
.else
EF_LANG=	ang
.endif

.if !defined(WITHOUT_QT)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui	\
		${PYTHON_SITELIBDIR}/PyQt4/QtAssistant.so:${PORTSDIR}/devel/py-qt4-assistant
SUB_FILES+=	qtEficas
PLIST_SUB+=	QT4=""
.else
PLIST_SUB+=	QT4="@comment "
.endif

FIXSHTK=	bureau.py cataediteur.py panels.py
FIXSHQT4=	typeNode.py
FIXBASH=	cataSTA9/Macro/macr_ecre_calc_ops.py cataSTA10/Macro/macr_ecre_calc_ops.py

pre-configure:
	${RM} ${WRKSRC}/convert/Parserv5/Translate.py.orig
	${RM} -r ${WRKSRC}/Pmw	# Use our ported Pmw
.for tk in TK QT4
. for FILE in ${FIXSH${tk}}
	${REINPLACE_CMD} -e "s|/usr/bin/sh|/bin/sh|" ${WRKSRC}/Interface${tk}/${FILE}
. endfor
.endfor
	${REINPLACE_CMD} -e "s#lang='fr'#lang='${EF_LANG}'#"			\
		${WRKSRC}/Aster/prefs.py
	${REINPLACE_CMD} -e "s#os.path.join(rep_cata,'..','Doc')#\"${DOCSDIR}\"#"	\
		-e "s#os.path.join(initialdir,'../Pmw')#'${PYTHON_SITELIBDIR}/Pmw'#"	\
		${WRKSRC}/Aster/editeur.ini
.for cata in ${FIXBASH}
	${REINPLACE_CMD} -e "s|'/bin/bash'|'${LOCALBASE}/bin/bash'|"	\
		${WRKSRC}/Aster/Cata/${cata}
.endfor
	${REINPLACE_CMD} -e 's|QListBoxItem\*|QListWidgetItem*|' ${WRKSRC}/InterfaceQT4/*.py

do-install:
	${MKDIR} ${EFICASDIR}
	${CP} -R ${WRKSRC}/* ${EFICASDIR}
	${FIND} ${EFICASDIR} -name CMakeFiles -delete
	${FIND} ${EFICASDIR} -name CVS | ${XARGS} ${RM} -rf
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

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
