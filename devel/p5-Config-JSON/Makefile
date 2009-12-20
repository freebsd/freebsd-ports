# New ports collection makefile for:	p5-Config-JSON
# Date created:		2008-07-31
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	Config-JSON
PORTVERSION=	1.5000
CATEGORIES=	devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A JSON based config file system

RUN_DEPENDS=    p5-Class-InsideOut>=1.06:${PORTSDIR}/devel/p5-Class-InsideOut \
		p5-JSON>=2.12:${PORTSDIR}/converters/p5-JSON
BUILD_DEPENDS=  ${RUN_DEPENDS}
BUILD_DEPENDS+= p5-Test-Deep>=0.095:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Moose>=0.93:${PORTSDIR}/devel/p5-Moose \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

PERL_CONFIGURE=	Yes
MAN3=		Config::JSON.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500905
BUILD_DEPENDS+=	p5-Test-Simple>=0.7:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	p5-File-Temp>=0.18:${PORTSDIR}/devel/p5-File-Temp \
		p5-Scalar-List-Utils>=1.19:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-version>=0.72.03:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
