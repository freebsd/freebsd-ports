# Created by: Yuan-Chung Hsiao <ychsiao@ychsiao.org>
# $FreeBSD$

PORTNAME=	IO-Toolkit
PORTVERSION=	1.008
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LINMAR/${PORTNAME:S/-//}
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Perl extension to create logfiles

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-RC6>=0:security/p5-Crypt-RC6
RUN_DEPENDS=	p5-Crypt-RC6>=0:security/p5-Crypt-RC6

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
