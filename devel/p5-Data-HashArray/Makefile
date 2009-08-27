# New ports collection makefile for:	Data::HashArray
# Date created:		2009-08-27
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-HashArray
PORTVERSION=	1.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Array class of hashes with properties via overloading and AUTOLOAD

BUILD_DEPENDS=	p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils

PERL_CONFIGURE=	yes

MAN3=		Data::HashArray.3

.include <bsd.port.mk>
