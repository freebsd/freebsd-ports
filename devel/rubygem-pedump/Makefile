PORTNAME=	pedump
PORTVERSION=	0.7.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dump headers, sections, extract resources of Win32 PE exe, dll, etc
WWW=		https://pedump.me/ \
		https://github.com/zed-0xff/pedump

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-iostruct>=0.7.0:devel/rubygem-iostruct \
		rubygem-logger>=0:devel/rubygem-logger \
		rubygem-zhexdump>=0.0.2:devel/rubygem-zhexdump

USES=		gem python:env shebangfix

NO_ARCH=	yes

PLIST_FILES=	bin/pedump

SHEBANG_FILES=	data/ordlookup/pefile2json.py

.include <bsd.port.mk>
