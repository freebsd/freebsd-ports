# New ports collection makefile for:	p5-T2
# Date created:	   			19 January 2004
# Whom:		   			Scott McWhirter <scott@surreytech.co.uk>
#
# $FreeBSD$
#

PORTNAME=	T2
PORTVERSION=	0.07
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tangram/SAMV
PKGNAMEPREFIX=	p5-

MAINTAINER=	scott@surreytech.co.uk
COMMENT=	Object Relational mapping system

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Set/Object.pm:${PORTSDIR}/devel/p5-Set-Object \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Tangram.pm:${PORTSDIR}/databases/p5-Tangram \
		${SITE_PERL}/Class/Tangram.pm:${PORTSDIR}/devel/p5-Class-Tangram
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		T2.3 T2::Association.3 T2::Attribute.3 T2::Class.3 \
		T2::Schema.3 T2::Storage.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Perl 5.6 or newer required. Install lang/perl5.8 or lang/perl5 and try again.
.endif

.include <bsd.port.post.mk>
