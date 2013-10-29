# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Git-PurePerl
PORTVERSION=	0.48
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BROQ
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure Perl interface to Git repositories

BUILD_DEPENDS=	p5-Archive-Extract>=0:${PORTSDIR}/archivers/p5-Archive-Extract \
		p5-Data-Stream-Bulk>=0:${PORTSDIR}/devel/p5-Data-Stream-Bulk \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-StrictConstructor>=0:${PORTSDIR}/devel/p5-MooseX-StrictConstructor \
		p5-MooseX-Types-Path-Class>=0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-IO-Digest>0:${PORTSDIR}/devel/p5-IO-Digest
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
