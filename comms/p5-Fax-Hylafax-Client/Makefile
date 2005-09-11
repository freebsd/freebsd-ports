# New ports collection makefile for:	p5-Fax-Hylafax-Client
# Date created:				September 10 2005
# Whom:				Tony Shadwick <tshadwick@oss-solutions.com>
#
# $FreeBSD$
#

PORTNAME=	Fax-Hylafax-Client
PORTVERSION=	1.01
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Fax
PKGNAMEPREFIX=	p5-

MAINTAINER=	tshadwick@oss-solutions.com
COMMENT=	A simple Perl client for the HylaFAX fax server

BUILD_DEPENDS=	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net

PERL_CONFIGURE=	yes

MAN3=		Fax::Hylafax::Client.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires Perl 5.8.0 or superior. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
