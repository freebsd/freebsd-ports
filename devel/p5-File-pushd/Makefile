# New ports collection makefile for:	devel/p5-File-pushd
# Date created:				04 November 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-pushd
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	File::pushd - temporary chdir for a limited scope

BUILD_DEPENDS=	${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	File::pushd.3

.include <bsd.port.mk>
