# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Notify-Filter-Markdown
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl module to convert SVN::Notify log messages from Markdown to HTML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-SVN-Notify>=2.70:devel/p5-SVN-Notify \
		p5-Text-Markdown>=1.04:textproc/p5-Text-Markdown
RUN_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-SVN-Notify>=2.70:devel/p5-SVN-Notify \
		p5-Text-Markdown>=1.04:textproc/p5-Text-Markdown

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
