# New ports collection makefile for:	Python module for SQL Relay
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
CATEGORIES=	databases python
MASTER_SITES=	# none
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${SQLRELAY_PORTDIR}:configure
LIB_DEPENDS=	sqlrclient.0:${SQLRELAY_PORTDIR}

USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src/api/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${SQLRELAY_CONFIGURE_ARGS} \
		--with-python-prefix="${LOCALBASE}"

.include "${.CURDIR}/../sqlrelay/Makefile.common"

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -fs `${SQLRELAY_WRKSRC_CMD}` ${WRKSRC}

.include <bsd.port.mk>
