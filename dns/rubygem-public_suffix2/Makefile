# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	public_suffix
PORTVERSION=	2.0.5
PORTREVISION=	1
CATEGORIES=	dns rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby domain name parser based on the Public Suffix List

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Use dns/rubygem-public_suffix instead
EXPIRATION_DATE=2017-09-30

PATCH_DEPENDS=	public_suffix_list>=0:dns/public_suffix_list

PORTSCOUT=	limit:^2\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

post-patch:
	@${CP} ${LOCALBASE}/share/public_suffix_list/public_suffix_list.dat ${WRKSRC}/data/definitions.txt

.include <bsd.port.mk>
