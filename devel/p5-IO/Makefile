# New ports collection makefile for:	IO
# Date created:		27 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	IO
PORTVERSION= 	1.20
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

USE_PERL5=	yes

MAN3=		IO::Pipe.3 IO::Dir.3 IO::Select.3 IO::File.3 IO.3 IO::Poll.3\
		IO::Socket::INET.3 IO::Socket.3 IO::Handle.3 \
		IO::Socket::UNIX.3 IO::Seekable.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL PREFIX=${PREFIX}\
		CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
