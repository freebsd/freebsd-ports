# New ports collection makefile for:	py-tagpy
# Date created:		2007-01-22
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tagpy
PORTVERSION=	0.91
PORTREVISON=	1
CATEGORIES=	audio python
MASTER_SITES=	http://news.tiker.net/news.tiker.net/download/software/${PORTNAME}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python bindings for Scott Wheeler's TagLib

LIB_DEPENDS=	boost_python.4:${PORTSDIR}/devel/boost-python \
		tag.5:${PORTSDIR}/audio/taglib

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    -e 's|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g' \
	    -e 's|%%PYTHON_LIBDIR%%|${PYTHON_LIBDIR}|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
