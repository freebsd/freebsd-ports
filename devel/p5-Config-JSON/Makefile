# New ports collection makefile for:	p5-Config-JSON
# Date created:		2008-07-31
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	Config-JSON
PORTVERSION=	1.5100
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A JSON based config file system

RUN_DEPENDS=	\
		p5-Scalar-List-Utils>=1.19:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-File-Temp>=0.18:${PORTSDIR}/devel/p5-File-Temp \
		p5-JSON>=2.16:${PORTSDIR}/converters/p5-JSON \
		p5-Any-Moose>=0.13:${PORTSDIR}/devel/p5-Any-Moose
BUILD_DEPENDS=  ${RUN_DEPENDS}

PERL_CONFIGURE=	Yes
MAN3=		Config::JSON.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500905
RUN_DEPENDS+=	p5-version>=0.72.03:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
