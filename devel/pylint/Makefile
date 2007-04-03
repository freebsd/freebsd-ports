# New ports collection makefile for:	pylint
# Date created:		28 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	pylint
PORTVERSION=	0.13.1
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.logilab.org/pub/pylint/	\
		http://ftp.logilab.org/pub/pylint/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analyzes python source code looking for bugs and signs of poor quality

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/logilab/astng/__init__.py:${PORTSDIR}/devel/py-astng

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You may want to install x11-toolkits/py-tkinter to make pylint-gui work."
	@${ECHO_CMD} ""

.include <bsd.port.mk>
