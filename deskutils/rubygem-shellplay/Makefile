# $FreeBSD$

PORTNAME=	shellplay
PORTVERSION=	0.1.8
CATEGORIES=	deskutils textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	mose@mose.com
COMMENT=	CLI tool for shell-based presentations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-paint>=1.0.0:${PORTSDIR}/devel/rubygem-paint \
	rubygem-cliprompt>=0.1.2:${PORTSDIR}/devel/rubygem-cliprompt \
	rubygem-configstruct>=0.1.0:${PORTSDIR}/devel/rubygem-configstruct \
	rubygem-shell2html>=0.0.5:${PORTSDIR}/textproc/rubygem-shell2html

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/shellcat bin/shellexport bin/shellplay bin/shellrecord

.include <bsd.port.mk>
