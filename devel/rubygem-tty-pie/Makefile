PORTNAME=	tty-pie
PORTVERSION=	0.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Draw pie charts in your terminal window
WWW=		https://ttytoolkit.org/ \
		https://github.com/piotrmurach/tty-pie

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-pastel>=0.8<1:devel/rubygem-pastel \
		rubygem-tty-cursor>=0.7<1:devel/rubygem-tty-cursor

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
