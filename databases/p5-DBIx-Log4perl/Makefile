# New ports collection makefile for:	p5-DBIx-Log4perl
# Date created:				2006-07-20
# Whom:					Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Log4perl
PORTVERSION=	0.08
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	For DBI to selectively log SQL, parameters, result-sets, transactions

BUILD_DEPENDS=	p5-DBI>=1.50:${PORTSDIR}/databases/p5-DBI \
		p5-Log-Log4perl>=1.04:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Log4perl.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires Perl 5.8.0 Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
