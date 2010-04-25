# New ports collection makefile for:	p5-File-Map
# Date created:				2010-04-15
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	File-Map
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jupengfei@gmail.com
COMMENT=	Memory mapping made simple and safe

BUILD_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Warn>0:${PORTSDIR}/devel/p5-Test-Warn \
		p5-Readonly>0:${PORTSDIR}/devel/p5-Readonly \
		p5-ExtUtils-CBuilder>0:${PORTSDIR}/devel/p5-ExtUtils-CBuilder

PERL_CONFIGURE=	YES

MAN3=		File::Map.3

.include <bsd.port.mk>
