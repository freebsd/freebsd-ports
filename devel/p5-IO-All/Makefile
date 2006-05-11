# New ports collection makefile for:	IO::All
# Date created:		15 July 2004
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	IO-All
PORTVERSION=	0.35
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/I/IN/INGY/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	IO::All combines all of the best Perl IO modules

RUN_DEPENDS=	${SITE_PERL}/Tie/File.pm:${PORTSDIR}/devel/p5-Tie-File \
		${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IO::All.3 \
		IO::All::DBM.3 \
		IO::All::Dir.3 \
		IO::All::File.3 \
		IO::All::Filesys.3 \
		IO::All::Link.3 \
		IO::All::MLDBM.3 \
		IO::All::Pipe.3 \
		IO::All::STDIO.3 \
		IO::All::Socket.3 \
		IO::All::String.3 \
		IO::All::Temp.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl then try again
.endif

.include <bsd.port.post.mk>
