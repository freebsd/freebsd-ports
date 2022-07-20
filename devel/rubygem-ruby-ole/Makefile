PORTNAME=	ruby-ole
PORTVERSION=	1.2.12.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library for easy read/write access to OLE compound documents

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/oletool

SHEBANG_FILES=	bin/oletool \
		test/*.rb

.include <bsd.port.mk>
