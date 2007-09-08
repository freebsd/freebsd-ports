# New ports collection makefile for:	p5-CommitBit
# Date created:		2006-12-30
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CommitBit
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/J/JE/JESSE
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A project administration tool

RUN_DEPENDS=	${SITE_PERL}/Module/CoreList.pm:${PORTSDIR}/devel/p5-Module-CoreList \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Jifty>=0.60728:${PORTSDIR}/www/p5-Jifty \
		p5-Text-Password-Pronounceable>=0:${PORTSDIR}/security/p5-Text-Password-Pronounceable

PERL_CONFIGURE=	5.8.3+

MAN3=		CommitBit.3 \
		CommitBit::Action::ConfirmEmail.3 \
		CommitBit::Action::Login.3 \
		CommitBit::Action::Logout.3 \
		CommitBit::Notification::ConfirmAddress.3 \
		CommitBit::Notification::InviteToProject.3

.include <bsd.port.mk>
