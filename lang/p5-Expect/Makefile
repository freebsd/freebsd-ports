# New ports collection makefile for:	p5-Expect
# Date created:		14 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	Expect
PORTVERSION=	1.16
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Expect
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Perl module inspired by the Tcl version of Expect

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IO/Tty.pm:${PORTSDIR}/devel/p5-IO-Tty \
		${SITE_PERL}/IO/Stty.pm:${PORTSDIR}/devel/p5-IO-Stty
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Expect.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or higher. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
