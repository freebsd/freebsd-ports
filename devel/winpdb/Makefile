# ex:ts=8
# Ports collection makefile for:	winpdb
# Date created:			Feb 15, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	winpdb
PORTVERSION=	1.0.8
CATEGORIES=	devel python
MASTER_SITES=	SF

MAINTAINER=	python@FreeBSD.org
COMMENT=	An advanced Python debugger

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_WX=		2.6
WX_COMPS=	python

post-install:
.for file in rpdb2 winpdb
	@${MV} -f ${PREFIX}/bin/_${file}.py ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
