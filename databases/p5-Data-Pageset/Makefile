# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Pageset
PORTVERSION=	1.06
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Page numbering and page sets

BUILD_DEPENDS=	p5-Data-Page>=2:${PORTSDIR}/databases/p5-Data-Page \
		p5-Test-Simple>=0.1:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Data::Pageset.3

USES=		perl5
USE_PERL5=	configure

NO_STAGE=	yes
.include <bsd.port.mk>
