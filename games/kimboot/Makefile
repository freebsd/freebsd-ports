# New ports collection makefile for:	kimboot
# Date created:		26 Jan 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	kimboot
PORTVERSION=	0.74
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	A sick and addictive arcade game

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/xode/__init__.py:${PORTSDIR}/devel/py-ode

USE_BZIP2=	yes
USE_PYTHON=	2.3+
NO_BUILD=	yes

SUB_FILES=	kimboot
SUB_LIST=	PROGRAM_DIR="${PREFIX}/lib/${PORTNAME}"

do-install:
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${PREFIX}/lib/${PORTNAME}/data
	${MKDIR} ${PREFIX}/lib/${PORTNAME}/menu
.for file in *.py hiscores options.xml
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/${PORTNAME}
.endfor
	${INSTALL_DATA} ${WRKSRC}/data/* ${PREFIX}/lib/${PORTNAME}/data
	${INSTALL_DATA} ${WRKSRC}/menu/* ${PREFIX}/lib/${PORTNAME}/menu
	${INSTALL_SCRIPT} ${WRKDIR}/kimboot ${PREFIX}/bin

.include <bsd.port.mk>
