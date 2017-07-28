# $FreeBSD$

PORTNAME=	shellplay
PORTVERSION=	0.1.9
CATEGORIES=	deskutils textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	mose@mose.com
COMMENT=	CLI tool for shell-based presentations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-cliprompt>=0.1.2:devel/rubygem-cliprompt \
		rubygem-configstruct>=0.1.0:devel/rubygem-configstruct \
		rubygem-paint>=2.0.0:devel/rubygem-paint \
		rubygem-shell2html>=0.0.6:textproc/rubygem-shell2html

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem
PLIST_FILES=	bin/shellcat bin/shellexport bin/shellplay bin/shellrecord

.include <bsd.port.mk>
