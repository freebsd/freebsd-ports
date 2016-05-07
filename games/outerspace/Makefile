# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	outerspace
PORTVERSION=	0.2.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/ospace/OSLauncher/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	On-line strategy game

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:devel/py-game

USES=		python
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	outerspace
SUB_LIST=	PROGRAM_DIR="${PREFIX}/lib/${PORTNAME}"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/outerspace|${PREFIX}/lib/${PORTNAME}/res|' ${WRKSRC}/outerspace

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} oslauncher ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} res ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}/outerspace ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/outerspace ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
