# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Perlish
PORTVERSION=	0.59
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A perlish interface to SQL databases

BUILD_DEPENDS=	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
		p5-PadWalker>0:${PORTSDIR}/devel/p5-PadWalker
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	DBIx::Perlish.3

.include <bsd.port.mk>
