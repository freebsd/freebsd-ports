# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	IO
PORTVERSION=	1.25
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Various IO modules for Perl

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	INSTALLDIRS=site POLLUTE=1

MAN3=		IO.3 IO::Dir.3 IO::File.3 IO::Handle.3 IO::Pipe.3 IO::Poll.3 \
		IO::Seekable.3 IO::Select.3 IO::Socket.3 IO::Socket::INET.3 \
		IO::Socket::UNIX.3

.include <bsd.port.mk>
