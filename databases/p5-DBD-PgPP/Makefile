# New ports collection makefile for:	p5-DBD-PgPP
# Date created:				August 8th 2004
# Whom:					Lubomir Marinov <lubomir_m@abv.bg>
#
# $FreeBSD$
#

PORTNAME=	DBD-PgPP
PORTVERSION=	0.05
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	lubomir_m@abv.bg
COMMENT=	Pure Perl PostgreSQL driver for the DBI

PERL_CONFIGURE=	yes

MAN3=	DBD::PgPP.3 DBD::DBD-PgPP.ja.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
post-patch:
	@${PERL} -i -pe 's/\[:graph:\] /\\x20-\\x7e/g' ${WRKSRC}/PgPP.pm
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
