# New ports collection makefile for:	p5-Storable
# Date created:				July 7th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Storable
PORTVERSION=	2.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Storable
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Storable.3

post-patch:
	${PERL} -pi -e '$$_="" if /MAN3PODS|INSTALLDIRS/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
