# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Geo-KML
PORTVERSION=	0.94
CATEGORIES=	graphics perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Module to Create Google Earth KML/KMZ

BUILD_DEPENDS=	p5-Archive-Zip>=1.30:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-Data-Peek>=0.32:${PORTSDIR}/devel/p5-Data-Peek \
		p5-Log-Report>=0.28:${PORTSDIR}/devel/p5-Log-Report \
		p5-XML-Compile>=1.18:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=0.97:${PORTSDIR}/textproc/p5-XML-Compile-Cache
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
