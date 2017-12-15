# Created by: J.F. Dockes
# $FreeBSD$

PORTNAME=	xapian-core
PORTVERSION=	1.0.23
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/
PKGNAMESUFFIX=	10

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Probabilistic text search database engine

LICENSE=	GPLv2

BROKEN_armv6=		fails to install: quartz_log.cc:: error: call to 'om_tostring' is ambiguous
BROKEN_armv7=		fails to install: quartz_log.cc:: error: call to 'om_tostring' is ambiguous
BROKEN_mips=		fails to install: quartz_log.cc:: error: call to 'om_tostring' is ambiguous
BROKEN_mips64=		fails to install: quartz_log.cc:: error: call to 'om_tostring' is ambiguous

CONFLICTS_INSTALL=	xapian-core xapian-core12

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS SSE2
SSE2_DESC=	Use SSE2 for floating point

SSE2_CONFIGURE_ENABLE=	sse

post-install:
.for f in delve quest copydatabase
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/${f} \
		${STAGEDIR}${PREFIX}/bin/xapian-${f}
.endfor

.include <bsd.port.mk>
