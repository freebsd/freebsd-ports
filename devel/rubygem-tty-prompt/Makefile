PORTNAME=	tty-prompt
PORTVERSION=	0.23.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Beautiful and powerful interactive command line prompt
WWW=		https://ttytoolkit.org/ \
		https://github.com/piotrmurach/tty-prompt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-pastel>=0.8<1:devel/rubygem-pastel \
		rubygem-tty-reader>=0.8<1:devel/rubygem-tty-reader

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
