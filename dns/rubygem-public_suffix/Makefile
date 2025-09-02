PORTNAME=	public_suffix
PORTVERSION=	6.0.2
PORTREVISION=	3
CATEGORIES=	dns rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby domain name parser based on the Public Suffix List
WWW=		https://github.com/weppos/publicsuffix-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PATCH_DEPENDS=	public_suffix_list>=0:dns/public_suffix_list

USES=		gem

NO_ARCH=	yes

post-patch:
	@${CP} ${LOCALBASE}/share/public_suffix_list/public_suffix_list.dat ${WRKSRC}/data/definitions.txt

.include <bsd.port.mk>
