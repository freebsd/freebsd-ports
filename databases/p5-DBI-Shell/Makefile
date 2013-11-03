# Created by: dcf@aracnet.com
# $FreeBSD$

PORTNAME=	DBI-Shell
PORTVERSION=	11.95
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interactive command shell for the DBI

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Text-Reform>=0:${PORTSDIR}/textproc/p5-Text-Reform \
		p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-IO-Tee>=0:${PORTSDIR}/devel/p5-IO-Tee
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
