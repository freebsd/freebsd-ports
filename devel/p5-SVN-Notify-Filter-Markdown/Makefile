# New ports collection makefile for:	SVN-Notify-Filter-Markdown
# Date created:		2008-04-21
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Notify-Filter-Markdown
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Perl module to convert SVN::Notify log messages from Markdown to HTML

RUN_DEPENDS=	p5-SVN-Notify>=2.70:${PORTSDIR}/devel/p5-SVN-Notify \
		p5-Text-Markdown>=0:${PORTSDIR}/textproc/p5-Text-Markdown \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
BUILD_DEPENDS=	p5-SVN-Notify>=2.70:${PORTSDIR}/devel/p5-SVN-Notify \
		p5-Text-Markdown>=0:${PORTSDIR}/textproc/p5-Text-Markdown \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser

PERL_MODBUILD=	yes

MAN3=		SVN::Notify::Filter::Markdown.3

.include <bsd.port.mk>
