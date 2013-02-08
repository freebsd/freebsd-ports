# Ports collection Makefile for:	Eficas
# Date created:				Jul 07 2003
# Whom:					thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	eficas
DISTVERSION=	6.4.0-1
PORTREVISION=	1
CATEGORIES=	french cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ASter Command FIle Editor

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/py-Pmw	\
		${PYTHON_SITELIBDIR}/mx:${PORTSDIR}/lang/py-mx-base		\
		${PYNUMPY}

USE_PYTHON=	yes
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

LEFICASDIR?=	apps/${PORTNAME}
EFICASDIR=	${PREFIX}/${LEFICASDIR}
PLIST_SUB=	EFICASDIR=${LEFICASDIR}
SUB_FILES=	qtEficas
SUB_LIST=	EFICASDIR=${EFICASDIR} PYTHON_CMD=${PYTHON_CMD}

.if defined(LANG) && ${LANG:Mfr*} != ""
EF_LANG=	fr
.else
EF_LANG=	ang
.endif

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui	\
		${PYTHON_SITELIBDIR}/PyQt4/QtAssistant.so:${PORTSDIR}/devel/py-qt4-assistant

FIXSHQT4=	typeNode.py
FIXBASH=	cataSTA9/Macro/macr_ecre_calc_ops.py	\
		cataSTA10/Macro/macr_ecre_calc_ops.py
FIXPMW=		Aster/editeur_salome.ini Aster/editeur.ini

pre-configure:
	${RM} ${WRKSRC}/convert/Parserv5/Translate.py.orig
.for FILE in ${FIXPMX}
	${REINPLACE_CMD} -e 's|../Pmw|${PYTHON_SITELIBDIR}/Pmw|' ${WRKSRC}/${FILE}
.endfor
.for FILE in ${FIXSHQT4}
	${REINPLACE_CMD} -e "s|/usr/bin/sh|/bin/sh|" ${WRKSRC}/InterfaceQT4/${FILE}
.endfor
	${REINPLACE_CMD} -e "s#lang='fr'#lang='${EF_LANG}'#"			\
		${WRKSRC}/Aster/prefs.py
	${REINPLACE_CMD} -e "s#os.path.join(rep_cata,'..','Doc')#\"${DOCSDIR}\"#"	\
		${WRKSRC}/Aster/editeur.ini
.for cata in ${FIXBASH}
	${REINPLACE_CMD} -e "s|'/bin/bash'|'${LOCALBASE}/bin/bash'|"	\
		${WRKSRC}/Aster/Cata/${cata}
.endfor

do-install:
	${MKDIR} ${EFICASDIR}
	${CP} -R ${WRKSRC}/* ${EFICASDIR}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${EFICASDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${EFICASDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/qtEficas ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/qtEficas ${PREFIX}/bin/eficas

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
