# New ports collection makefile for:	DBIx-ContextualFetch
# Date created:	   17 March 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	DBIx-ContextualFetch
PORTVERSION=	1.02
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx/TMTM
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Add contextual fetches to DBI

PERL_CONFIGURE=	yes

MAN3=		DBIx::ContextualFetch.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

BUILD_DEPENDS=	${RUN_DEPENDS}

.if ${PERL_LEVEL} < 500702
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e '$$_="" if /^use warnings/;' \
		${WRKSRC}/lib/DBIx/ContextualFetch.pm
.endif

.include <bsd.port.post.mk>
