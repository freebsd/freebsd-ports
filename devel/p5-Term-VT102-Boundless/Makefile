# Created by: Andrey Chernov <ache@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Term-VT102-Boundless
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Subclass to emulate boundless DEC VT102 terminal

LICENSE=	ART10 GPLv1 MIT
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Term-VT102>=0:devel/p5-Term-VT102
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
