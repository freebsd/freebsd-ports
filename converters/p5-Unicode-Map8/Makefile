# New ports collection makefile for:	p5-Unicode-Map8
# Date created:				20 September 2000
# Whom:					Ilia Chipitsine <ilia@jane.cgu.chel.su>
#
# $FreeBSD$

PORTNAME=	Unicode-Map8
PORTVERSION=	0.13
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mapping table between 8-bit chars and Unicode

BUILD_DEPENDS=	p5-Unicode-String>=2:${PORTSDIR}/converters/p5-Unicode-String
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		umap.1
MAN3=		Unicode::Map8.3

.include <bsd.port.mk>
