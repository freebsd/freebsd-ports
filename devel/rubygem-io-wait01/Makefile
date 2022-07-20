PORTNAME=	io-wait
PORTVERSION=	0.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	01

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Wait until IO is readable or writable without blocking

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.1\.

.include <bsd.port.mk>
