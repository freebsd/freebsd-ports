# ex:ts=8
# New ports collection makefile for:    happydoc
# Date created:         Dec 29, 2000
# Whom:                 Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	happydoc
PORTVERSION=	2.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	HappyDoc_r${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A tool for extracting documentation from Python source code

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_r/-r/}

.include <bsd.port.mk>
