# New ports collection makefile for:	p5-DateTime-Calendar-Japanese-Era
# Date created:		2007-05-16
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Calendar-Japanese-Era
PORTVERSION=	0.07
CATEGORIES=	japanese devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	ja-p5-

MAINTAINER=	markun@onohara.to
COMMENT=	DateTime Extension for Japanese Eras

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Calendar::Japanese::Era.3

.include <bsd.port.mk>
