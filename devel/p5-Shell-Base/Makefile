# New ports collection makefile for:	Shell::Base
# Date created:				Sat Jan 31 10:41:28 EST 2004
# Whom:					Christopher Nehren <apeiron@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	Shell-Base
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Shell
PKGNAMEPREFIX=	p5-

MAINTAINER=	apeiron@comcast.net
COMMENT=	Perl module implementing a simple command shell

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/Size.pm:${PORTSDIR}/devel/p5-Term-Size \
		${SITE_PERL}/Text/Shellwords.pm:${PORTSDIR}/textproc/p5-Text-Shellwords
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Shell::Base.3

.include <bsd.port.mk>
