# New ports collection makefile for:	devel/p5-P4
# Date created:				02 Sep 2003
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	P4
PORTVERSION=	1.4320
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	P4
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	P4 - Perl friendly OO interface to the Perforce SCM System

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/P4/UI.pm:${PORTSDIR}/devel/p5-P4-Client
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		P4.3

.include <bsd.port.mk>
