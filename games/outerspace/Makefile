# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	outerspace
PORTVERSION=	0.2.2
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/ospace/OSLauncher/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	On-line strategy game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYGAME}

USES=		python:2.7
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
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin/env python|${PYTHON_CMD}|' ${STAGEDIR}${PREFIX}/bin/outerspace

.include <bsd.port.mk>
