# New ports collection makefile for:	devel/p5-Parse-CPAN-Packages
# Date created:				Mar 27 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Parse-CPAN-Packages
PORTVERSION=	2.20
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Parse
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse 02packages.details.txt.gz from CPAN

BUILD_DEPENDS=	${SITE_PERL}/Sort/Versions.pm:${PORTSDIR}/devel/p5-Sort-Versions \
		${SITE_PERL}/CPAN/DistnameInfo.pm:${PORTSDIR}/devel/p5-CPAN-DistnameInfo \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Parse::CPAN::Packages.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
# make PREFIX-clean under perl 5.005_03
post-configure:
	${PERL} -pi -e 's,/usr/local/,\$$(PREFIX)/,g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
