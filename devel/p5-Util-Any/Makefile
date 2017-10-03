# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Util-Any
PORTVERSION=	0.25
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KTAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Export any utilities and create your own utility module

LICENSE=	ART10

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

RUN_DEPENDS=	p5-Clone>=0:devel/p5-Clone \
		p5-ExportTo>=0:devel/p5-ExportTo \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-List-Pairwise>0:devel/p5-List-Pairwise \
		p5-Module-Pluggable>0:devel/p5-Module-Pluggable \
		p5-String-CamelCase>0:textproc/p5-String-CamelCase \
		p5-String-Util>0:textproc/p5-String-Util

.include <bsd.port.mk>
