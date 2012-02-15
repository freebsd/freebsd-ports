# New ports collection makefile for:	p5-Glib2
# Date created:				26 Oct 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Glib2
PORTVERSION=	1.250
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/Glib SF/gtk2-perl/Glib/${PORTVERSION}
PKGNAMEPREFIX=	p5-
DISTNAME=	Glib-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	This module provides access to Glib and GObject libraries

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends

USE_GNOME=	glib20
PERL_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:S/2//}-${PORTVERSION}

MAN3=	Glib.3 Glib::BookmarkFile.3 Glib::Boxed.3 Glib::CodeGen.3 \
	Glib::Error.3 Glib::Flags.3 Glib::GenPod.3 Glib::KeyFile.3 \
	Glib::Log.3 Glib::MainLoop.3 Glib::MakeHelper.3 Glib::Markup.3 \
	Glib::Object.3 Glib::Object::Subclass.3 Glib::OptionContext.3 \
	Glib::OptionGroup.3 Glib::Param::Double.3 Glib::Param::Enum.3 \
	Glib::Param::Flags.3 Glib::Param::GType.3 Glib::Param::Int.3 \
	Glib::Param::Int64.3 Glib::Param::UInt.3 Glib::Param::UInt64.3 \
	Glib::ParamSpec.3 Glib::ParseXSDoc.3 Glib::Signal.3 Glib::Type.3 \
	Glib::Utils.3 Glib::devel.3 Glib::index.3 Glib::version.3 Glib::xsapi.3

pre-everything::
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "Some functions of this module require a threaded perl."
	@${ECHO_MSG} "If you intend to use them or experience hangs when"
	@${ECHO_MSG} "using this module, enable the THREADS option in perl."
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>
