# New ports collection makefile for:	pybaz
# Date created:		2007-03-01
# Whom:			Radim Kolar <hsn@sanatana.dharma>
#
# $FreeBSD$
#

PORTNAME=	pybaz
PORTVERSION=	1.5.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://code.aaronbentley.com/pybaz/releases/

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Python interface to Baz/Arch version control system

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PLIST_SUB+=	PYTHON_SITELIB=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||}

RUN_DEPENDS=	baz:${PORTSDIR}/devel/bazaar

.include <bsd.port.mk>
