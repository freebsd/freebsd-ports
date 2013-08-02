# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	Parse-CPAN-Packages-Fast
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse CPAN's package index

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CPAN-DistnameInfo>=0:${PORTSDIR}/devel/p5-CPAN-DistnameInfo \
		p5-PerlIO-gzip>=0:${PORTSDIR}/archivers/p5-PerlIO-gzip
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Parse::CPAN::Packages::Fast.3

.include <bsd.port.mk>
