PORTNAME=	npth
PORTVERSION=	1.8
CATEGORIES=	devel
MASTER_SITES=	GNUPG

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	New GNU Portable Threads
WWW=		https://www.gnupg.org/software/npth/index.html

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		libtool pathfix tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
