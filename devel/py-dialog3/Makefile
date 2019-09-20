# $FreeBSD$

PORTNAME=	dialog
PORTVERSION=	3.4.0
CATEGORIES=	devel python
MASTER_SITES=	SF/python${PORTNAME}/python${PORTNAME}/${PORTVERSION} \
		LOCAL/jkim
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3
DISTNAME=	python3-pythondialog-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Python 3 interface to dialog(3)

LICENSE=	LGPL20

RUN_DEPENDS=	cdialog:devel/cdialog

USES=		python:3.6 tar:bz2
USE_PYTHON=	autoplist concurrent distutils pythonprefix
PYDISTUTILS_PKGNAME=	python${PORTNAME}

WRKSRC=		"${WRKDIR}/${DISTNAME:C/^python3-//}"

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! -name *\.orig"

.include <bsd.port.mk>
