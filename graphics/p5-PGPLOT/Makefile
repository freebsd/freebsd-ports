# Created by: jmz
# $FreeBSD$

PORTNAME=	PGPLOT
PORTVERSION=	2.21
PORTREVISION=	15
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KGB
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 extension which makes available the pgplot library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-ExtUtils-F77>=1.13:lang/p5-ExtUtils-F77
LIB_DEPENDS=	libpgplot.so:graphics/pgplot \
		libpng.so:graphics/png

USES=		fortran perl5 xorg
USE_XORG=	x11
INSTALL_TARGET=	pure_install
TEST_TARGET=	test
SCRIPTS_ENV=	PERL=${PERL}

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} test* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
