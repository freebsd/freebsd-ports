# New ports collection makefile for:	p5-Date-Calc
# Date created:				25 February 2000
# Whom:	      				Brad Hendrickse <bradh@uunet.co.za>
#
# $FreeBSD$
#

PORTNAME=	Date-Calc
PORTVERSION=	5.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	bradh@uunet.co.za

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Bit/Vector.pm:${PORTSDIR}/math/p5-Bit-Vector
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Date::Calc.3 Date::Calc::Object.3 Date::Calendar.3 \
		Date::Calendar::Profiles.3 Date::Calendar::Year.3
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
