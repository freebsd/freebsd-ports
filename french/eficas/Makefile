# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	eficas
DISTVERSION=	7.3.0-1
CATEGORIES=	french cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ASter Command FIle Editor

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/py-Pmw	\
		${PYTHON_SITELIBDIR}/mx:${PORTSDIR}/lang/py-mx-base		\
		bash:${PORTSDIR}/shells/bash					\
		${PYNUMPY}

BROKEN=		ImportError in numpy: cannot import name scimath

USES=		shebangfix
USE_PYTHON=	yes
SHEBANG_FILES=	eficas eficasQt
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

FIXUBIN=	Openturns_Study/prefs_OPENTURNS_STUDY.py	\
		Openturns_Wrapper/prefs_OPENTURNS_WRAPPER.py	\
		Aster/prefs_ASTER.py

pre-configure:
	${REINPLACE_CMD} -e "s#lang='fr'#lang='${EF_LANG}'#"		\
		${WRKSRC}/Aster/prefs.py
.for FILE in ${FIXUBIN}
	${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/${FILE}
.endfor
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|;s|%%PREFIX%%|${PREFIX}|'	\
		-e 's|%%EFICASDIR%%|${EFICASDIR}|' ${WRKSRC}/eficasQt

do-install:
	${MKDIR} ${STAGEDIR}${EFICASDIR}
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${EFICASDIR}
	(cd ${STAGEDIR}${PREFIX} \
		 && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		 -d ${PREFIX} -f ${EFICASDIR:S;${PREFIX}/;;})
	(cd ${STAGEDIR}${PREFIX} \
		 && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		 -d ${PREFIX} -f ${EFICASDIR:S;${PREFIX}/;;})
	${RM} ${STAGEDIR}${EFICASDIR}/convert/Parserv5/Translate.py.orig	\
		${STAGEDIR}${EFICASDIR}/eficasQt.orig				\
		${STAGEDIR}${EFICASDIR}/InterfaceQT4/typeNode.py.orig
	${INSTALL_SCRIPT} ${WRKSRC}/eficasQt ${STAGEDIR}${PREFIX}/bin
	${LN} -sf eficasQt ${STAGEDIR}${PREFIX}/bin/eficas

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
