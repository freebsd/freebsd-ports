# New ports collection makefile for:	p5-Class-DBI-ToSax
# Date created:	   22 july 2003
# Whom:		   Mathieu Arnold <mat@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-ToSax
PORTVERSION=	0.10
CATEGORIES=	databases textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Extension to Class::DBI for sqlite

RUN_DEPENDS=	${SITE_PERL}/Ima/DBI.pm:${PORTSDIR}/databases/p5-Ima-DBI \
		${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/XML/SAX/Writer.pm:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		${SITE_PERL}/NEXT.pm:${PORTSDIR}/devel/p5-NEXT
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::ToSax.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
# I really begin to hate either perl programmers or 5.005_03 ;)
post-patch:
	@${PERL} -pi -e '$$_ = "" if (/use 5.006|use warnings/);' \
		     -e 's/^our ([^\s;]+)/use vars qw($$1); $$1/;' \
		     -e 's/\$$self->\$$col/$$&()/g;' \
		     ${WRKSRC}/lib/Class/DBI/ToSax.pm ${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
