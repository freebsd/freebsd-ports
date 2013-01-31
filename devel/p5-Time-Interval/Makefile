# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Time-Interval
PORTVERSION=	1.231
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Converts time intervals of days, hours, minutes, and seconds

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-TimeDate>0:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Time::Interval.3

post-patch:
.for dotfile in ._Changes ._Interval.pm ._Interval.pod ._Makefile.PL ._README ._test.pl
	${RM} -f ${WRKSRC}/${dotfile}
.endfor

.include <bsd.port.mk>
