# New ports collection makefile for:	Data::Localize
# Date created:		09 Mar 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Localize
PORTVERSION=	0.00021
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for alternate data localization API

RUN_DEPENDS=	\
	p5-Any-Moose>0:${PORTSDIR}/devel/p5-Any-Moose \
	p5-MooseX-AttributeHelpers>0:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Data::Localize.3 \
	Data::Localize::Auto.3 \
	Data::Localize::Gettext.3 \
	Data::Localize::Format.3 \
	Data::Localize::Format::Gettext.3 \
	Data::Localize::Format::Maketext.3 \
	Data::Localize::Format::NamedArgs.3 \
	Data::Localize::Gettext::Parser.3 \
	Data::Localize::Localizer.3 \
	Data::Localize::MultiLevel.3 \
	Data::Localize::Namespace.3 \
	Data::Localize::Storage.3 \
	Data::Localize::Storage::BerkeleyDB.3 \
	Data::Localize::Trait::WithStorage.3 \
	Data::Localize::Util.3 \
	Data::Localize::Storage::Hash.3

.include <bsd.port.mk>
