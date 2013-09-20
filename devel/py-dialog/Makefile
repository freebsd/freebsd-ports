# Created by: ijliao
# $FreeBSD$

PORTNAME=	dialog
PORTVERSION=	2.7
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	SF/python${PORTNAME}/python${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pythondialog-${PORTVERSION}

MAINTAINER=	mek@mek.uz.ua
COMMENT=	Python interface to dialog(3)

RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pythondialog

EXAMPLESDIR=	${PREFIX}/share/examples/py-dialog

NO_STAGE=	yes
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo.py ${EXAMPLESDIR}

.include <bsd.port.mk>
