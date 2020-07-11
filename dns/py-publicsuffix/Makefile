# Created by: Dmitry Pryadko <d.pryadko@rambler-co.ru>
# $FreeBSD$

PORTNAME=	publicsuffix
PORTVERSION=	1.1.0
PORTREVISION=	30
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	d.pryadko@rambler-co.ru
COMMENT=	Get public suffix of domain name from Public Suffix List

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PATCH_DEPENDS=	public_suffix_list>=0:dns/public_suffix_list

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

post-patch:
	@${CP} ${LOCALBASE}/share/public_suffix_list/public_suffix_list.dat ${WRKSRC}/publicsuffix/public_suffix_list.dat

.include <bsd.port.mk>
