# ex:ts=8
# Ports collection makefile for:	pythondialog
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dialog
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pythondialog
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pythondialog-${PORTVERSION}

RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to dialog(3)

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
