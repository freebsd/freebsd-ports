# New ports collection makefile for:	p5-IO-Tty
# Date created:		14 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	IO-Tty
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Flexible I/O Perl5 module that allows manipulation of pseudo-TTYs

PERL_CONFIGURE=	yes

MAN3=		IO::Pty.3 \
		IO::Tty.3 \
		IO::Tty::Constant.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or higher. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
