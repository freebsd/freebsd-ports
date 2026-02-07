PORTNAME=	highline
PORTVERSION=	3.1.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	High-level IO library for command-line interfaces
WWW=		https://github.com/JEG2/highline

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-reline>=0:devel/rubygem-reline

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	bin/test

.include <bsd.port.mk>
