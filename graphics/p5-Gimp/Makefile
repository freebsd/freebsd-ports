PORTNAME=	Gimp
PORTVERSION=	2.38
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write GIMP extensions/plug-ins/load- and save-handlers in Perl
WWW=		https://metacpan.org/release/Gimp

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/COPYING.Artistic

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-ExtUtils-Depends>=0.402:devel/p5-ExtUtils-Depends \
		p5-Alien-Gimp>=0.01:graphics/p5-Alien-Gimp
LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp-app
RUN_DEPENDS=	p5-Gtk2>=1.0:x11-toolkits/p5-Gtk2 \
		p5-Gtk2-Ex-PodViewer>=0:x11-toolkits/p5-Gtk2-Ex-PodViewer \
		p5-IO-All>=0:devel/p5-IO-All \
		p5-IO-Stringy>=0:devel/p5-IO-Stringy \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-PDL>=2.064:math/p5-PDL \
		p5-Web-Scraper>=0:www/p5-Web-Scraper

USES=		perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Gimp/Gimp.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Gimp/Lib/Lib.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Gimp/Net/Net.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Gimp/UI/UI.so

.include <bsd.port.mk>
