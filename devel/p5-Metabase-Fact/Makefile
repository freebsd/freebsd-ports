# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Metabase-Fact
PORTVERSION=	0.021
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Metabase Facts

BUILD_DEPENDS=	p5-JSON>=2.0:${PORTSDIR}/converters/p5-JSON \
		p5-Data-GUID>=0:${PORTSDIR}/devel/p5-Data-GUID \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-CPAN-DistnameInfo>0:${PORTSDIR}/devel/p5-CPAN-DistnameInfo
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

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

NO_STAGE=	yes
.include <bsd.port.mk>
