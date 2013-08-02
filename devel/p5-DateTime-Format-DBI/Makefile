# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Format-DBI
PORTVERSION=	0.040
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Find a parser class for a database connection

RUN_DEPENDS=	p5-DBI>=1.21:${PORTSDIR}/databases/p5-DBI \
		p5-DateTime>=0.1:${PORTSDIR}/devel/p5-DateTime
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	modbuild

MAN3=		DateTime::Format::DBI.3

.include <bsd.port.mk>
