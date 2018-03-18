# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty-markdown
PORTVERSION=	0.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert markdown document/text into terminal friendly output

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-kramdown>=1.16.2:textproc/rubygem-kramdown \
		rubygem-pastel>=0.7.2:devel/rubygem-pastel \
		rubygem-rouge>=3.1.0:textproc/rubygem-rouge \
		rubygem-strings>=0.1.0:devel/rubygem-strings \
		rubygem-tty-color>=0.4.2:devel/rubygem-tty-color \
		rubygem-tty-screen>=0.6.4:devel/rubygem-tty-screen

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
