# New ports collection makefile for:	Python/Ming
# Date created:		16 Oct 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-py-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module for Ming which allows you to create Flash 4/5 movies

LIB_DEPENDS=	ming.4:${PORTSDIR}/graphics/ming

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/py_ext

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	mingc
PYDISTUTILS_PKGVERSION=	0.0.3a

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' ${WRKSRC}/setup.py
	@${LN} -sf ${LOCALBASE}/include/ming ${WRKSRC}/../src

.include <bsd.port.mk>
