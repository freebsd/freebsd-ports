# New ports collection makefile for:	p5-Mozilla-PublicSuffix
# Date created:		2012-03-14
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mozilla-PublicSuffix
PORTVERSION=	0.1.8
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Get public suffix of domain name via Mozilla Public Suffix List

LICENSE=	MIT

BUILD_DEPENDS=	p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_MODBUILD=	yes

MAN3=		Mozilla::PublicSuffix.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-HTTP-Tiny>=0:${PORTSDIR}/www/p5-HTTP-Tiny
.endif

.include <bsd.port.post.mk>
