# New ports collection makefile for:	jacode.pl
# Date created:		2011-05-11
# Whom:			Takefu
#
# $FreeBSD$
#

PORTNAME=	jacode.pl
PORTVERSION=	2.13.4.9
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IN/INA/${PORTNAME:S|.pl||}
DISTNAME=	${PORTNAME:S|.pl||}-${PORTVERSION}

MAINTAINER=	takefu@airport.fm
COMMENT=	Perl library for Japanese character code conversion

USE_PERL5_RUN=	yes
PLIST_FILES=	${SITE_PERL_REL}/${PORTNAME}
NO_BUILD=	yes

LICENSE=	GPLv1 ART10
LICENSE_COMB=	dual

pre-install:
	@cd ${WRKSRC}; ${PERL} ${WRKSRC}/test.pl

do-install:
	@${MKDIR} ${PREFIX}/${SITE_PERL_REL}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${PREFIX}/${SITE_PERL_REL}/${PORTNAME}

.include <bsd.port.mk>
