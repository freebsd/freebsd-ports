# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	eficas
DISTVERSION=	7.5.0-1
CATEGORIES=	french cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ASter Command FIle Editor

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Pmw>0:x11-toolkits/py-Pmw	\
		${PYTHON_PKGNAMEPREFIX}mx-base>0:lang/py-mx-base		\
		bash:shells/bash					\
		${PYNUMPY}

USES=		shebangfix python
USE_GCC=	yes # To be removed - Needed as a work-around for numpy, see PR ports/188114
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

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:x11-toolkits/py-qt4-gui	\
		xdg-open:devel/xdg-utils

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
		-e 's|%%EFICASDIR%%|${EFICASDIR}|;s|%%GCC_RUNTIME%%|${_GCC_RUNTIME}|'	\
		${WRKSRC}/eficasQt

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
