PORTNAME=	pry
PORTVERSION=	0.16.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	IRB alternative and runtime developer console
WWW=		http://pryrepl.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-coderay>=1.1<2:textproc/rubygem-coderay \
		rubygem-method_source>=1.0<2:devel/rubygem-method_source \
		rubygem-reline>=0.6.0:devel/rubygem-reline

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/pry

.include <bsd.port.mk>
