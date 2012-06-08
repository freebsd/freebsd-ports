# New ports collection makefile for:	p5-CommitBit
# Date created:		2006-12-30
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CommitBit
PORTVERSION=	0.02
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JESSE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A project administration tool

RUN_DEPENDS=	p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Jifty>=0.60728:${PORTSDIR}/www/p5-Jifty \
		p5-Text-Password-Pronounceable>=0:${PORTSDIR}/security/p5-Text-Password-Pronounceable

PERL_CONFIGURE=	yes

MAN3=		CommitBit.3 \
		CommitBit::Action::ConfirmEmail.3 \
		CommitBit::Action::Login.3 \
		CommitBit::Action::Logout.3 \
		CommitBit::Model::User.3 \
		CommitBit::Notification::ConfirmAddress.3 \
		CommitBit::Notification::InviteToProject.3 \
		CommitBit::Test.3

.include <bsd.port.mk>
