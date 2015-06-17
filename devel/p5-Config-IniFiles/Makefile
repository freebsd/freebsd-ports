# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Config-IniFiles
PORTVERSION=	2.87
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Read .ini-style configuration files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-List-MoreUtils>=0.33:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.33:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.33:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
