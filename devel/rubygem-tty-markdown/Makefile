# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty-markdown
PORTVERSION=	0.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert markdown document/text into terminal friendly output

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-kramdown>=1.16.2<3.0:textproc/rubygem-kramdown \
		rubygem-pastel>=0.8<1:devel/rubygem-pastel \
		rubygem-rouge>=3.14<4:textproc/rubygem-rouge \
		rubygem-strings>=0.2.0<1:devel/rubygem-strings \
		rubygem-tty-color>=0.5<1:devel/rubygem-tty-color \
		rubygem-tty-screen>=0.8<1:devel/rubygem-tty-screen

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
