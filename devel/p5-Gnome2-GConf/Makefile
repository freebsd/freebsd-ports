# New ports collection makefile for:	p5-Gnome2-GConf
# Date created:			02 Apr 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	Gnome2-GConf
PORTVERSION=	1.044
PORTREVISION=	2
CATEGORIES=	devel gnome perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl bindings for the GConf2 configuration engine

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/CodeGen.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2

PERL_CONFIGURE=	5.8.0+
USE_GNOME=	gconf2

MAN3=		Gnome2::GConf.3 \
		Gnome2::GConf::ChangeSet.3 \
		Gnome2::GConf::Client.3 \
		Gnome2::GConf::Engine.3 \
		Gnome2::GConf::Entry.3 \
		Gnome2::GConf::Schema.3 \
		Gnome2::GConf::Value.3 \
		Gnome2::GConf::index.3 \
		Gnome2::GConf::main.3 \
		Gnome2::GConf::version.3

.include <bsd.port.mk>
