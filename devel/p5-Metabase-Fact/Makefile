# New ports collection makefile for:	p5-Metabase-Fact
# Date created:		2011-02-05
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Metabase-Fact
PORTVERSION=	0.019
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DA/DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Metabase Facts

BUILD_DEPENDS=	p5-JSON>=2.0:${PORTSDIR}/converters/p5-JSON \
		p5-Data-GUID>=0:${PORTSDIR}/devel/p5-Data-GUID \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-CPAN-DistnameInfo>0:${PORTSDIR}/devel/p5-CPAN-DistnameInfo
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	metabase-profile.1
MAN3=	Metabase::Fact.3 Metabase::Resource::metabase.3 \
	Metabase::Resource::perl::commit.3 \
	Metabase::Resource::perl.3 \
	Metabase::Resource::metabase::fact.3 \
	Metabase::Resource::cpan.3 \
	Metabase::Resource::cpan::distfile.3 \
	Metabase::Resource::metabase::user.3 \
	Metabase::User::Secret.3 \
	Metabase::Fact::String.3 \
	Metabase::Fact::Hash.3 \
	Metabase::Resource.3 \
	Metabase::User::EmailAddress.3 \
	Metabase::User::FullName.3 \
	Metabase::User::Profile.3 \
	Metabase::Report.3

.include <bsd.port.mk>
