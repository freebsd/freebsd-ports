# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	Class-DBI-Pager
PORTVERSION=	0.08
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pager utility for Class::DBI

BUILD_DEPENDS:=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI \
		p5-Exporter-Lite>=0:${PORTSDIR}/devel/p5-Exporter-Lite \
		p5-Data-Page>=0:${PORTSDIR}/databases/p5-Data-Page \
		p5-Clone>=0:${PORTSDIR}/devel/p5-Clone

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
