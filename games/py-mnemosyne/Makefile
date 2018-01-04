# Created by: Beech Rintoul <beech@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mnemosyne
PORTVERSION=	2.3.6
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	games python
MASTER_SITES=	SF/mnemosyne-proj/${PORTNAME}/${PORTNAME}-${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mnemosyne-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flash-card tool which optimises your learning process

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.2.0:math/py-matplotlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cherrypy>=3.2:www/py-cherrypy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.2:www/py-webob@${FLAVOR}

USES=		fortran pyqt:4 python:2.7
USE_PYQT=	gui_run network_run sql_run webkit_run
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PLIST_FILES=	bin/mnemosyne

_GCC_LD_PATH=	${LOCALBASE}/lib/gcc${GCC_DEFAULT:S/.//}

.include <bsd.port.pre.mk>

post-extract:
	@${LN} -sf mnemosyne ${WRKSRC}/mnemosyne/pyqt_ui/mnemosyne.exec

post-patch:
	@${REINPLACE_CMD} -e 's|\(pyqt_ui/mnemosyne\)"|\1.exec"| ; \
		 s|\(share/\)icons|\1pixmaps|' ${WRKSRC}/setup.py

post-build:
	@${MKDIR} ${WRKDIR}/wrappers
	@${ECHO_CMD} '#!${SH}' > ${WRKDIR}/wrappers/mnemosyne
.if ${OPSYS} == FreeBSD && ${fortran_ARGS} == gcc
	@${ECHO_CMD} 'LD_LIBRARY_PATH="${_GCC_LD_PATH}:$$LD_LIBRARY_PATH"' \
		>> ${WRKDIR}/wrappers/mnemosyne
	@${ECHO_CMD} 'export LD_LIBRARY_PATH' >> ${WRKDIR}/wrappers/mnemosyne
.endif
	@${ECHO_CMD} 'exec ${PREFIX}/bin/mnemosyne.exec "$$@"' >> ${WRKDIR}/wrappers/mnemosyne

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/wrappers/mnemosyne ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
