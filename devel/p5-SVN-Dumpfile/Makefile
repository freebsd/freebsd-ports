# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Dumpfile
PORTVERSION=	0.13.107
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to access and manipulate Subversion dumpfiles

BUILD_DEPENDS=	p5-Data-GUID>=0:devel/p5-Data-GUID \
		p5-TimeDate>=2.27:devel/p5-TimeDate \
		p5-Readonly>=1.03:devel/p5-Readonly
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
