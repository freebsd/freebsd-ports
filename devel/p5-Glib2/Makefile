# New ports collection makefile for:	p5-Glib2
# Date created:				26 Oct 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Glib2
PORTVERSION=	1.020
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	../by-authors/id/R/RM/RMCFARLA/Gtk2-Perl \
		gtk2-perl
PKGNAMEPREFIX=	p5-
DISTNAME=	Glib-${PORTVERSION}

MAINTAINER=	clsung@dragon2.net
COMMENT=	This module provides access to Glib and GObject libraries

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	glib20
PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	disable-threadsafe

MAN3=		Glib.3 \
		Glib::Boxed.3 \
		Glib::Flags.3 \
		Glib::GenPod.3 \
		Glib::Log.3 \
		Glib::MainLoop.3 \
		Glib::Object.3 \
		Glib::Object::Subclass.3 \
		Glib::ParamSpec.3 \
		Glib::ParseXSDoc.3 \
		Glib::Signal.3 \
		Glib::Type.3 \
		Glib::devel.3 \
		Glib::index.3 \
		Glib::xsapi.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This port requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
