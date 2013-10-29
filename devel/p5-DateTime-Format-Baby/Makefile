# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Format-Baby
PORTVERSION=	1.0100
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse and format baby-style time

RUN_DEPENDS=	p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime
BUILD_DEPENDS:=	${RUN_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME:S/00//}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
