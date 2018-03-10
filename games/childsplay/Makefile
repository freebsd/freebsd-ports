# Created by: bruno
# $FreeBSD$

PORTNAME=	childsplay
PORTVERSION=	2.6.5
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Educative games for children

LICENSE=	GPLv3 # only
LICENSE_FILE=	${WRKSRC}/gpl-3.0.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>0:devel/py-game@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>0:databases/py-sqlalchemy10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}game>0:devel/py-game@${PY_FLAVOR}

NO_BUILD=	yes

USES=		gettext shebangfix tar:tgz python:2.7
USE_GNOME=	pygtk2

SHEBANG_FILES=	childsplay.py
.for i in buttons funcs text dialogs gtk_widgets base
SHEBANG_FILES+=	SPWidgets/$i.py
.endfor

DESKTOP_ENTRIES="Childsplay" "" "" "${PORTNAME}" "Game;Education;" ""

CHILDSPLAYDIR=	${PYTHONPREFIX_SITELIBDIR}/childsplay

post-patch:
	@${REINPLACE_CMD} -e \
		'/NoGtk/s|True|False|' ${WRKSRC}/SPConstants.py
	@${REINPLACE_CMD} -e \
		's|/usr/local|${PREFIX}|' ${WRKSRC}/pangofont.py

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
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "SPWidgets alphabetsounds lib" \
		${STAGEDIR}${CHILDSPLAYDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} locale ${STAGEDIR}${PREFIX}/share)
	${INSTALL_DATA} ${WRKSRC}/sp_content.db ${STAGEDIR}${CHILDSPLAYDIR}
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
