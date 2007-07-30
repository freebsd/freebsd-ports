# New ports collection makefile for:	p5-Class-Adapter
# Date created:		2006-08-13
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Class-Adapter
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Perl implementation of the "Adapter" Design Pattern

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Adapter.3 \
		Class::Adapter::Builder.3 \
		Class::Adapter::Clear.3

.include <bsd.port.mk>
