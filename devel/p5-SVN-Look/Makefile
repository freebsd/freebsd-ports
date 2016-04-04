# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Look
PORTVERSION=	0.41
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cpm@fbsd.es
COMMENT=	Caching wrapper around the svnlook command

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		subversion>=1.7.0:devel/subversion
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
