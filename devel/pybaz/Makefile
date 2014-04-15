# Created by: Radim Kolar <hsn@sanatana.dharma>
# $FreeBSD$

PORTNAME=	pybaz
PORTVERSION=	1.5.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://code.aaronbentley.com/pybaz/releases/

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Python interface to Baz/Arch version control system

LICENSE=	GPLv2

RUN_DEPENDS=	baz:${PORTSDIR}/devel/baz

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PLIST_SUB+=	PYTHON_SITELIB=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||}

.include <bsd.port.mk>
