PORTNAME=	red-datasets
PORTVERSION=	0.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide common datasets
WWW=		https://github.com/red-data-tools/red-datasets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-csv>=3.2.4:devel/rubygem-csv \
		rubygem-rexml>=0:textproc/rubygem-rexml \
		rubygem-rubyzip>=0:archivers/rubygem-rubyzip

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
