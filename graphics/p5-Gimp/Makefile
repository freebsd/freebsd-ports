# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	Gimp
PORTVERSION=	2.31
PORTREVISION=	3
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write GIMP extensions/plug-ins/load- and save-handlers in Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Gtk2>=1.0:x11-toolkits/p5-Gtk2 \
		p5-Gtk2-Ex-PodViewer>=0:x11-toolkits/p5-Gtk2-Ex-PodViewer \
		p5-IO-All>=0:devel/p5-IO-All \
		p5-IO-stringy>=0:devel/p5-IO-stringy \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Web-Scraper>=0:www/p5-Web-Scraper \
		PDL>=2.007:math/PDL
BUILD_DEPENDS:=	p5-ExtUtils-Depends>=0.200:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1:devel/p5-ExtUtils-PkgConfig \
		${RUN_DEPENDS}
LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp-app

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
