# New ports collection makefile for:	p5-DBIx-Password
# Date created:				March 17th 2002
# Whom:	      				Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Password
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	autrijus@autrijus.org
COMMENT=	Allows you to create a global password file for DB passwords

PERL_CONFIGURE=	yes

MAN3=		DBIx::Password.3

.if defined(BATCH)
EXTRA_PATCHES+=	${FILESDIR}/batch.patch
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
