# ex:ts=8
# Ports collection makefile for:	showgrammar
# Date Created:			Jul 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	showgrammar
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	http://se.wtb.tue.nl/~hat/showgrammar/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.py

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert a yacc grammar to syntax diagrams

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/spark.py:${PORTSDIR}/devel/py-spark

PLIST_FILES=	bin/showgrammar
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}
USE_PYTHON=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|#!/usr/bin/python|#!/usr/bin/env python|g" ${WRKSRC}/${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTFILES} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
