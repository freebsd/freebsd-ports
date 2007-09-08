# New ports collection makefile for:	IO
# Date created:		27 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	IO
PORTVERSION=	1.20
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Various IO modules for Perl

PERL_CONFIGURE=	5.6.0-
USE_PERL5_REASON=	this module is already included in perl 5.6.x and later
CONFIGURE_ARGS=	INSTALLDIRS=site POLLUTE=1

MAN3=		IO.3 IO::Dir.3 IO::File.3 IO::Handle.3 IO::Pipe.3 IO::Poll.3 \
		IO::Seekable.3 IO::Select.3 IO::Socket.3 IO::Socket::INET.3 \
		IO::Socket::UNIX.3

DEPRECATED=	only works with old, unsupported Perl versions
EXPIRATION_DATE=	2007-09-11

.include <bsd.port.mk>
