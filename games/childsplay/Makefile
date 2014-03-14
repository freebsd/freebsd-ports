# Created by: bruno
# $FreeBSD$

PORTNAME=	childsplay
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Childsplay/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Educative games for children

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>0:${PORTSDIR}/devel/py-game
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>0:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}game>0:${PORTSDIR}/devel/py-game

NO_BUILD=	yes

USES=		gettext shebangfix
USE_GNOME=	pygtk2
USE_PYTHON=	2

python_OLD_CMD=	/usr/bin/env python
python_CMD=	/usr/bin/env python2
SHEBANG_FILES=	childsplay.py

DESKTOP_ENTRIES="Childsplay" "" "" "${PORTNAME}" "Game;Education;" ""

post-patch:
	@${REINPLACE_CMD} -e \
		'/NoGtk/s|True|False|' ${WRKSRC}/SPConstants.py
	@${REINPLACE_CMD} -e \
		's|/usr/local|${PREFIX}|' ${WRKSRC}/pangofont.py

do-configure:
	@${ECHO_CMD} "#!${SH}" > ${WRKDIR}/childsplay.sh
	@${ECHO_CMD} >> ${WRKDIR}/childsplay.sh
	@${ECHO_CMD} 'cd "${PYTHONPREFIX_SITELIBDIR}/childsplay"' >> ${WRKDIR}/childsplay.sh
	@${ECHO_CMD} 'exec ${PYTHON_CMD} childsplay.py $$@' >> ${WRKDIR}/childsplay.sh

do-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} childsplay.sh \
		${STAGEDIR}/${PREFIX}/bin/childsplay)
	@${MKDIR} ${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/childsplay
	(cd ${WRKSRC} && ${INSTALL_DATA} *.py \
		${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/childsplay)
.for i in SPWidgets alphabetsounds lib
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} \
		${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/childsplay)
.endfor
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	@${MKDIR} ${STAGEDIR}/${PREFIX}/share/locale
	(cd ${WRKSRC}/locale && ${COPYTREE_SHARE} . \
		${STAGEDIR}/${PREFIX}/share/locale)
	${INSTALL_DATA} ${WRKSRC}/sp_content.db \
		${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/childsplay

.include <bsd.port.mk>
