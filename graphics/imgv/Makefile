# Created by: Simon Olofsson <simon@olofsson.de>
# $FreeBSD$

PORTNAME=	imgv
PORTVERSION=	3.1.6
DISTVERSIONSUFFIX=	-src
PORTREVISION=	5
CATEGORIES=	graphics python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unique and feature rich Image Viewer

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>0:${PORTSDIR}/devel/py-game \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		python:run shebangfix
SHEBANG_FILES=	imgv.py

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/gl.py

do-configure:
	@${ECHO_CMD} -n > ${WRKSRC}/__init__.py

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} imgv.py \
		${STAGEDIR}${PREFIX}/bin/imgv)
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/imgv
	(cd ${WRKSRC} && ${FIND} . -maxdepth 1 -type f \
		-name "*.py" -a ! -name "setup.py" -a ! -name "imgv.py" | \
		${XARGS} -J % ${INSTALL_DATA} % \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/imgv)
	@${MKDIR} ${STAGEDIR}${DATADIR}/data
	(cd ${WRKSRC}/data && ${INSTALL_DATA} * \
		${STAGEDIR}${DATADIR}/data)
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
