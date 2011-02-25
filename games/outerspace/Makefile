# New ports collection makefile for:	outerspace
# Date created:		27 Mar 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	outerspace
PORTVERSION=	0.2.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/ospace/OSLauncher/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	On-line strategy game

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	2.5+
NO_BUILD=	yes

SUB_FILES=	outerspace
SUB_LIST=	PROGRAM_DIR="${PREFIX}/lib/${PORTNAME}"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/outerspace|${PREFIX}/lib/${PORTNAME}/res|' ${WRKSRC}/outerspace

do-install:
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} oslauncher ${PREFIX}/lib/${PORTNAME})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} res ${PREFIX}/lib/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}/outerspace ${PREFIX}/lib/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/outerspace ${PREFIX}/bin

	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
