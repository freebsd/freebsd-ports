# $FreeBSD$

PORTNAME=	jacode.pl
PORTVERSION=	2.13.4.18
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INA/${PORTNAME:S|.pl||}
DISTNAME=	${PORTNAME:S|.pl||}-${PORTVERSION}

MAINTAINER=	takefu@airport.fm
COMMENT=	Perl library for Japanese character code conversion

LICENSE=	GPLv1 ART10
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	run
PLIST_FILES=	${SITE_PERL_REL}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

pre-install:
	@cd ${WRKSRC}; ${PERL} ${WRKSRC}/t/001_test.t

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}

.include <bsd.port.mk>
