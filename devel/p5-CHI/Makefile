# New ports collection makefile for:	CHI
# Date created:		02 Mar 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CHI
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/J/JS/JSWARTZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for unified cache interface

RUN_DEPENDS=	\
	p5-Data-UUID>0:${PORTSDIR}/devel/p5-Data-UUID \
	p5-Digest-JHash>0:${PORTSDIR}/security/p5-Digest-JHash \
	p5-Hash-MoreUtils>0:${PORTSDIR}/devel/p5-Hash-MoreUtils \
	p5-List-MoreUtils>=0.13:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Mouse>=0.15:${PORTSDIR}/devel/p5-Mouse \
	p5-Time-Duration>=1.06:${PORTSDIR}/devel/p5-Time-Duration \
	p5-Time-Duration-Parse>=0.03:${PORTSDIR}/devel/p5-Time-Duration-Parse
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	CHI.3 \
	CHI::CacheObject.3 \
	CHI::Driver.3 \
	CHI::Driver::Base::CacheContainer.3 \
	CHI::Driver::CacheCache.3 \
	CHI::Driver::Development.3 \
	CHI::Driver::FastMmap.3 \
	CHI::Driver::File.3 \
	CHI::Driver::Memory.3 \
	CHI::Driver::Multilevel.3 \
	CHI::Driver::Null.3

.include <bsd.port.mk>
