# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty-markdown
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert markdown document/text into terminal friendly output

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-kramdown1>=1.16.2<2:textproc/rubygem-kramdown1 \
		rubygem-pastel>=0.7.2<1:devel/rubygem-pastel \
		rubygem-rouge>=3.3<4:textproc/rubygem-rouge \
		rubygem-strings>=0.1.4<0.2:devel/rubygem-strings \
		rubygem-tty-color>=0.4<1:devel/rubygem-tty-color \
		rubygem-tty-screen>=0.6<1:devel/rubygem-tty-screen

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
