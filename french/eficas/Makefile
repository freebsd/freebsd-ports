# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	eficas
DISTVERSION=	6.6.0-2
PORTREVISION=	2
CATEGORIES=	french cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ASter Command FIle Editor

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/py-Pmw	\
		${PYTHON_SITELIBDIR}/mx:${PORTSDIR}/lang/py-mx-base		\
		bash:${PORTSDIR}/shells/bash					\
		${PYNUMPY}

USE_PYTHON=	yes
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

LEFICASDIR?=	apps/${PORTNAME}
EFICASDIR=	${PREFIX}/${LEFICASDIR}
PLIST_SUB=	EFICASDIR=${LEFICASDIR}
SUB_LIST=	EFICASDIR=${EFICASDIR} PYTHON_CMD=${PYTHON_CMD}

.if defined(LANG) && ${LANG:Mfr*} != ""
EF_LANG=	fr
.else
EF_LANG=	ang
.endif

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui	\
		${PYTHON_SITELIBDIR}/PyQt4/QtAssistant.so:${PORTSDIR}/devel/py-qt4-assistant

FIXSHQT4=	typeNode.py
FIXBASH=	Aster/Cata/cataSTA9/Macro/macr_ecre_calc_ops.py	\
		Aster/Cata/cataSTA10/Macro/macr_ecre_calc_ops.py
FIXUBIN=	Openturns_Study/prefs_OPENTURNS_STUDY.py	\
		Openturns_Study/prefs_OPENTURNS_STUDY.py.in	\
		Openturns_Wrapper/prefs_OPENTURNS_WRAPPER.py	\
		Openturns_Wrapper/prefs_OPENTURNS_WRAPPER.py.in	\
		Aster/prefs_ASTER.py

NO_STAGE=	yes
pre-configure:
.for FILE in ${FIXSHQT4}
	${REINPLACE_CMD} -e "s|/usr/bin/sh|/bin/sh|" ${WRKSRC}/InterfaceQT4/${FILE}
.endfor
	${REINPLACE_CMD} -e "s#lang='fr'#lang='${EF_LANG}'#"		\
		${WRKSRC}/Aster/prefs.py
.for cata in ${FIXBASH}
	${REINPLACE_CMD} -e "s|'/bin/bash'|'${LOCALBASE}/bin/bash'|"	\
		${WRKSRC}/${cata}
.endfor
	${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|" ${WRKSRC}/eficasQt
.for FILE in ${FIXUBIN}
	${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/${FILE}
.endfor
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|;s|%%PREFIX%%|${PREFIX}|'	\
		-e 's|%%EFICASDIR%%|${EFICASDIR}|' ${WRKSRC}/eficasQt

do-install:
	${MKDIR} ${EFICASDIR}
	${CP} -R ${WRKSRC}/* ${EFICASDIR}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${EFICASDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${EFICASDIR}
	${RM} ${EFICASDIR}/convert/Parserv5/Translate.py.orig ${EFICASDIR}/eficasQt.orig
	${INSTALL_SCRIPT} ${WRKSRC}/eficasQt ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/eficasQt ${PREFIX}/bin/eficas

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
