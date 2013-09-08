# Created by: Max Campos <mcampos@bpsw.biz>
# $FreeBSD$

PORTNAME=	User-Identity
PORTVERSION=	0.93
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mcampos@bpsw.biz
COMMENT=	Perl module for abstracting information about a physical person

RUN_DEPENDS=	p5-Geography-Countries>=0:${PORTSDIR}/misc/p5-Geography-Countries

USES=		perl5
USE_PERL5=	configure

MAN3=		Mail::Identity.3 \
		User::Identity.3 \
		User::Identity::Archive.3 \
		User::Identity::Archive::Plain.3 \
		User::Identity::Collection.3 \
		User::Identity::Collection::Emails.3 \
		User::Identity::Collection::Locations.3 \
		User::Identity::Collection::Systems.3 \
		User::Identity::Collection::Users.3 \
		User::Identity::Item.3 \
		User::Identity::Location.3 \
		User::Identity::System.3

.include <bsd.port.mk>
