# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Notify-Filter-Markdown
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to convert SVN::Notify log messages from Markdown to HTML

RUN_DEPENDS=	p5-SVN-Notify>=2.70:${PORTSDIR}/devel/p5-SVN-Notify \
		p5-Text-Markdown>=1.04:${PORTSDIR}/textproc/p5-Text-Markdown \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
BUILD_DEPENDS=	p5-SVN-Notify>=2.70:${PORTSDIR}/devel/p5-SVN-Notify \
		p5-Text-Markdown>=1.04:${PORTSDIR}/textproc/p5-Text-Markdown \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser

USES=		perl5
USE_PERL5=	modbuild

MAN3=		SVN::Notify::Filter::Markdown.3

NO_STAGE=	yes
.include <bsd.port.mk>
