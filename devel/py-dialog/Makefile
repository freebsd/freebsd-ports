# ex:ts=8
# Ports collection makefile for:	pythondialog
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dialog
PORTVERSION=	1.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pythondialog
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dialog
EXTRACT_SUFX=	.py

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Dialog

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/dialog.py
USE_PYTHON=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dialog.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
