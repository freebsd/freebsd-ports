# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mozilla-PublicSuffix
PORTVERSION=	0.1.19
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Get public suffix of domain name via Mozilla Public Suffix List

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI
PATCH_DEPENDS=	public_suffix_list>=0:${PORTSDIR}/dns/public_suffix_list
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	modbuild
USES=		perl5

post-patch:
	@${CP} ${LOCALBASE}/share/public_suffix_list/public_suffix_list.dat ${WRKSRC}/effective_tld_names.dat

.include <bsd.port.mk>
