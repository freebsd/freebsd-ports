# New ports collection makefile for:	p5-Date-Easter
# Date created:				Sun May 23 11:36:48 CEST 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Date-Easter
PORTVERSION=	1.14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Calculates Easter for any given year

PERL_CONFIGURE=	yes

MAN3=		Date::Easter.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
# make PREFIX-clean under perl 5.005_03
post-configure:
	${PERL} -pi -e 's,/usr/local/,\$$(PREFIX)/,g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
