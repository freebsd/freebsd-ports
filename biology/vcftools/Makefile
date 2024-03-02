PORTNAME=	vcftools
PORTVERSION=	0.1.16
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for working with VCF genomics files
WWW=		https://github.com/vcftools/vcftools

LICENSE=	LGPL3

USES=		autoreconf cpe gmake perl5 pkgconfig

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GITHUB=	yes

CXXFLAGS+=	-std=c++14

CPE_VENDOR=	vcftools_project

.include <bsd.port.mk>
