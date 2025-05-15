PORTNAME=	vcftools
PORTVERSION=	0.1.17
DISTVERSIONPREFIX=	v
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for working with VCF genomics files
WWW=		https://github.com/vcftools/vcftools

LICENSE=	LGPL3

USES=		autoreconf cpe gmake perl5 pkgconfig
USE_GITHUB=	yes

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CXXFLAGS+=	-std=c++14

CPE_VENDOR=	vcftools_project

.include <bsd.port.mk>
