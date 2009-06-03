# Ports collection Makefile for:		SVN::Notify
# Date created:					22 Feb 2005
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	SVN-Notify
PORTVERSION=	2.79
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Subversion activity notification

RUN_DEPENDS=	${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/Net/SMTP_auth.pm:${PORTSDIR}/mail/p5-Net-SMTP_auth \
		p5-Text-Trac>=0.10:${PORTSDIR}/textproc/p5-Text-Trac \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		svnnotify.1
MAN3=		SVN::Notify.3 SVN::Notify::Alternative.3 SVN::Notify::HTML.3 \
		SVN::Notify::HTML::ColorDiff.3 SVN::Notify::Filter.3 SVN::Notify::Filter::Trac.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
RUN_DEPENDS+=	p5-Getopt-Long>=2.34:${PORTSDIR}/devel/p5-Getopt-Long
.endif

.include <bsd.port.post.mk>
