# Ports collection Makefile for:	py-roxlib
# Date created:				Jan 12 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	roxlib
PORTVERSION=	2.0.6
CATEGORIES=	devel python
MASTER_SITES=	SFP
MASTER_SITE_SUBDIR=rox/ROX-Lib/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	rox-lib2-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Python libraries for ROX

USE_BZIP2=	yes
USE_PYTHON=	yes

RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
		${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}
	@cd ${WRKSRC}/ROX-Lib2/python && ${PYTHON_CMD} make_docs.py

do-install:
	@${CP} -r ${WRKSRC}/ROX-Lib2 ${PREFIX}/lib
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/ROX-Lib2

.include <bsd.port.mk>
