# New ports collection makefile for:	Encode::JP::Mobile
# Date created:		23 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Encode-JP-Mobile
PORTVERSION=	0.27
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for encoding for mobile phones in Japan

RUN_DEPENDS=	\
	p5-File-ShareDir>=0.05:${PORTSDIR}/devel/p5-File-ShareDir
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
