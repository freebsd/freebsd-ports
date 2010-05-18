# New ports collection makefile for:	SVN::Hooks
# Date created:		2009-01-27
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Hooks
PORTVERSION=	0.28
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A framework for implementing Subversion hooks

RUN_DEPENDS=	p5-Email-Send>=0:${PORTSDIR}/mail/p5-Email-Send \
		p5-Email-Simple>=0:${PORTSDIR}/mail/p5-Email-Simple \
		p5-SVN-Look>=0:${PORTSDIR}/devel/p5-SVN-Look \
		p5-SVN-Notify>=0:${PORTSDIR}/devel/p5-SVN-Notify \
		p5-JIRA-Client>=0:${PORTSDIR}/devel/p5-JIRA-Client \
		${SITE_PERL}/XMLRPC/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SVN::Hooks.3 \
		SVN::Hooks::AllowLogChange.3 \
		SVN::Hooks::AllowPropChange.3 \
		SVN::Hooks::CheckCapability.3 \
		SVN::Hooks::CheckJira.3 \
		SVN::Hooks::CheckLog.3 \
		SVN::Hooks::CheckMimeTypes.3 \
		SVN::Hooks::CheckProperty.3 \
		SVN::Hooks::CheckStructure.3 \
		SVN::Hooks::DenyChanges.3 \
		SVN::Hooks::DenyFilenames.3 \
		SVN::Hooks::JiraAcceptance.3 \
		SVN::Hooks::Mailer.3 \
		SVN::Hooks::Notify.3 \
		SVN::Hooks::UpdateConfFile.3

.include <bsd.port.mk>
