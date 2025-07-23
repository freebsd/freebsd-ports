PORTNAME=	xapian-core
PORTVERSION=	1.4.29
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Probabilistic text search database engine
WWW=		https://xapian.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang libtool tar:xz

CONFIGURE_ARGS=	ac_cv_func_snprintf=snprintf
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	xapian-core12 # include/xapian.h

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	DOCS SSE2
SSE2_DESC=	Use SSE2 for floating point

SSE2_CONFIGURE_ENABLE=	sse

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xapian-inspect ${STAGEDIR}${PREFIX}/bin/xapian-inspect

.include <bsd.port.mk>
