# New ports collection makefile for:	py-gdchart2
# Date created:				2005-06-30
# Whom:					Choe, Cheng-Dae <whitekid@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gdchart
DISTVERSION=	2.0-beta1
CATEGORIES=	graphics python
MASTER_SITES=	http://www.nullcube.com/software/pygdchart2/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygdchart2

MAINTAINER=	whitekid@gmail.com
COMMENT=	Python interface to GDChart2

LIB_DEPENDS=	gdc.1:${PORTSDIR}/graphics/gdchart

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}gdchart-0.*

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}2

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
