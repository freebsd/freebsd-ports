# New ports collection makefile for:	p5-Unicode-Map8
# Date created:				20 September 2000
# Whom:					Ilia Chipitsine <ilia@jane.cgu.chel.su>
#
# $FreeBSD$

PORTNAME=	Unicode-Map8
PORTVERSION=	0.12
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Unicode
PKGNAMEPREFIX=	p5-

MAINTAINER=	ilia@cgu.chel.su
COMMENT=	Mapping table between 8-bit chars and Unicode

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String

PERL_CONFIGURE=	yes

MAN1=		umap.1
MAN3=		Unicode::Map8.3

.include <bsd.port.mk>
