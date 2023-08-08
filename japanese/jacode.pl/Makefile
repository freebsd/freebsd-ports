PORTNAME=	jacode.pl
DISTVERSION=	2.13.4.31
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INA/${PORTNAME:S|j|J|:S|.pl||}
DISTNAME=	${PORTNAME:S|j|J|:S|.pl||}-${PORTVERSION}

MAINTAINER=	takefu@airport.fm
COMMENT=	Perl library for Japanese character code conversion
WWW=		https://metacpan.org/dist/Jacode/

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${SITE_PERL_REL}/${PORTNAME}\
		${SITE_PERL_REL}/${PORTNAME:S|j|J|:S|.pl|.pm|}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME:S|j|J|:S|.pl|.pm|} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/

.include <bsd.port.mk>
