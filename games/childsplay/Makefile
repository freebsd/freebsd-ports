# Created by: bruno
# $FreeBSD$

PORTNAME=	childsplay
DISTVERSION=	3.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Educative games for children

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv3 # only
LICENSE_FILE=	${WRKSRC}/gpl-3.0.txt

BUILD_DEPENDS=	${PYGAME}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>0:databases/py-sqlalchemy10@${PY_FLAVOR} \
		${PYGAME}

USES=		gettext gnome python:2.7 shebangfix tar:tgz
USE_GNOME=	pygtk2
NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	childsplay.py
.for i in buttons funcs text dialogs base
SHEBANG_FILES+=	SPWidgets/$i.py
.endfor

DESKTOP_ENTRIES="Childsplay" "" "" "${PORTNAME}" "Game;Education;" ""

CHILDSPLAYDIR=	${PYTHONPREFIX_SITELIBDIR}/childsplay

do-configure:
	@${ECHO_CMD} "#!${SH}" > ${WRKDIR}/childsplay.sh
	@${ECHO_CMD} >> ${WRKDIR}/childsplay.sh
	@${ECHO_CMD} 'cd "${CHILDSPLAYDIR}"' >> ${WRKDIR}/childsplay.sh
	@${ECHO_CMD} 'exec ${PYTHON_CMD} childsplay.py "$$@"' \
		>> ${WRKDIR}/childsplay.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/childsplay.sh \
		${STAGEDIR}${PREFIX}/bin/childsplay
	@${MKDIR} ${STAGEDIR}${CHILDSPLAYDIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${STAGEDIR}${CHILDSPLAYDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "SPWidgets alphabet-sounds lib" \
		${STAGEDIR}${CHILDSPLAYDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} locale ${STAGEDIR}${PREFIX}/share
	${INSTALL_DATA} ${WRKSRC}/sp_content.db ${STAGEDIR}${CHILDSPLAYDIR}
	cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

.include <bsd.port.mk>
