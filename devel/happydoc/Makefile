# ex:ts=8
# New ports collection makefile for:    happydoc
# Date created:         Dec 29, 2000
# Whom:                 Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	happydoc
PORTVERSION=	1.4
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	HappyDoc_r${PORTVERSION:S/./_/}

MAINTAINER=	ijliao@FreeBSD.org

USE_PYTHON=	yes

NO_BUILD=	yes
WRKSRC=	${WRKDIR}/${DISTNAME:S/_r/-r/}

do-install:
	@(cd ${WRKSRC}; ${PYTHON_CMD} ./setup.py install)

.include <bsd.port.mk>
