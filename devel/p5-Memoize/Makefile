# New ports collection makefile for:	devel/p5-Memoize
# Date created:				12 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Memoize
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Memoize
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Memoize.3 \
		Memoize::AnyDBM_File.3 \
		Memoize::Expire.3 \
		Memoize::ExpireFile.3 \
		Memoize::ExpireTest.3 \
		Memoize::NDBM_File.3 \
		Memoize::SDBM_File.3 \
		Memoize::Saves.3 \
		Memoize::Storable.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	${PERL} -pi -e '$$_=";" if /warnings::/' ${WRKSRC}/Memoize.pm

.include <bsd.port.mk>
