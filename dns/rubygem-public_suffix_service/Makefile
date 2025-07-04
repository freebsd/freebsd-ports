PORTNAME=	public_suffix_service
PORTVERSION=	0.9.1
PORTREVISION=	102
CATEGORIES=	dns rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse and decompose domain names into TLD, domain, and subdomains
WWW=		http://www.simonecarletti.com/code/public_suffix_service

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PATCH_DEPENDS=	public_suffix_list>=0:dns/public_suffix_list

USES=		gem

NO_ARCH=	yes

post-patch:
	@${CP} ${LOCALBASE}/share/public_suffix_list/public_suffix_list.dat ${WRKSRC}/lib/public_suffix/definitions.txt

.include <bsd.port.mk>
