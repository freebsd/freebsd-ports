PORTNAME=	tty-table
PORTVERSION=	0.12.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fexible and intuitive table generator
WWW=		https://ttytoolkit.org/ \
		https://github.com/piotrmurach/tty-table

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-pastel>=0.8<1:devel/rubygem-pastel \
		rubygem-strings>=0.2.0<0.3:devel/rubygem-strings \
		rubygem-tty-screen>=0.8<1:devel/rubygem-tty-screen

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
