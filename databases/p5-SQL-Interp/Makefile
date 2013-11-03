# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SQL-Interp
PORTVERSION=	1.22
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interpolate Perl variables into SQL with DBI

BUILD_DEPENDS=	p5-DBI>=1:${PORTSDIR}/databases/p5-DBI \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS=	p5-DBI>=1:${PORTSDIR}/databases/p5-DBI \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
