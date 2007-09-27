# Ports collection Makefile for:		SVN::Notify
# Date created:					22 Feb 2005
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	SVN-Notify
PORTVERSION=	2.65
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SVN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Subversion activity notification

RUN_DEPENDS=	${SITE_PERL}/Net/SMTP_auth.pm:${PORTSDIR}/mail/p5-Net-SMTP_auth \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		svnnotify.1
MAN3=		SVN::Notify.3 SVN::Notify::Alternative.3 SVN::Notify::HTML.3 SVN::Notify::HTML::ColorDiff.3

.include <bsd.port.mk>
