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

LICENSE=	LGPL20

RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog

USES=		tar:bzip2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pythondialog

EXAMPLESDIR=	${PREFIX}/share/examples/py-dialog

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
