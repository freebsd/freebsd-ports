# New ports collection makefile for:	p5-Glib2
# Date created:				26 Oct 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Glib2
PORTVERSION=	1.040
PORTREVISION=	0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/$/:cpan/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	../by-authors/id/R/RM/RMCFARLA/Gtk2-Perl/:cpan \
		gtk2-perl/:sf
PKGNAMEPREFIX=	p5-
DISTFILES=	Glib-${PORTVERSION}${EXTRACT_SUFX}:cpan \
		Glib-${PORTVERSION}${EXTRACT_SUFX}:sf

MAINTAINER=	clsung@dragon2.net
COMMENT=	This module provides access to Glib and GObject libraries

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends

USE_GNOME=	glib20
PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	disable-threadsafe
USE_GMAKE=	yes

MAN3=		Glib.3 \
		Glib::Boxed.3 \
		Glib::Error.3 \
		Glib::Flags.3 \
		Glib::GenPod.3 \
		Glib::Log.3 \
		Glib::MainLoop.3 \
		Glib::MakeHelper.3 \
		Glib::Object.3 \
		Glib::Object::Subclass.3 \
		Glib::ParamSpec.3 \
		Glib::ParseXSDoc.3 \
		Glib::Signal.3 \
		Glib::Type.3 \
		Glib::Utils.3 \
		Glib::devel.3 \
		Glib::index.3 \
		Glib::version.3 \
		Glib::xsapi.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This port requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
