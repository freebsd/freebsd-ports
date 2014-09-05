# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	Gimp
PORTVERSION=	2.31
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write GIMP extensions/plug-ins/load- and save-handlers in Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Gtk2>=1.0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		PDL>=2.007:${PORTSDIR}/math/PDL \
		p5-IO-All>=0:${PORTSDIR}/devel/p5-IO-All \
		p5-Gtk2-Ex-PodViewer>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-PodViewer \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Web-Scraper>=0:${PORTSDIR}/www/p5-Web-Scraper \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.200:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${RUN_DEPENDS}
LIB_DEPENDS=	libgimp-2.0.so:${PORTSDIR}/graphics/gimp-app

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
