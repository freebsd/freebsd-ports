# New ports collection makefile for:	p5-Gnome2-GConf
# Date created:			02 Apr 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		Gnome2-GConf
PORTVERSION=		1.000
PORTREVISION=	1
CATEGORIES=		devel gnome perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gnome2
PKGNAMEPREFIX=		p5-

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		Perl bindings for the GConf2 configuration engine

BUILD_DEPENDS=		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
			${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
			${SITE_PERL}/${PERL_ARCH}/Gtk2/CodeGen.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2
RUN_DEPENDS=		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2

PERL_CONFIGURE=		yes
USE_GMAKE=		yes
USE_GNOME=		gconf2

MAN3=			Gnome2::GConf.3 \
			Gnome2::GConf::ChangeSet.3 \
			Gnome2::GConf::Client.3 \
			Gnome2::GConf::Entry.3 \
			Gnome2::GConf::Schema.3 \
			Gnome2::GConf::Value.3 \
			Gnome2::GConf::index.3 \
			Gnome2::GConf::version.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=			"Needs perl 5.8.0 or higher, install lang/perl5.8 and try again"
.endif

.include <bsd.port.post.mk>
