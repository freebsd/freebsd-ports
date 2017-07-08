# Created by: J.F. Dockes
# $FreeBSD$

PORTNAME=	xapian-core
PORTVERSION=	1.4.4
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Probabilistic text search database engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to configure: A compiler with support for C++11 language features is required

CONFLICTS_INSTALL=	xapian-core10 xapian-core12

OPTIONS_DEFINE=	DOCS SSE2
SSE2_DESC=	Use SSE2 for floating point

PORTSCOUT=	limitw:1,even

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool pathfix tar:xz

PORTDATA=	*
PORTDOCS=	*

SSE2_CONFIGURE_ENABLE=	sse

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/copydatabase ${STAGEDIR}${PREFIX}/bin/xapian-copydatabase
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/quest ${STAGEDIR}${PREFIX}/bin/xapian-quest
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/xapian-metadata ${STAGEDIR}${PREFIX}/bin/xapian-metadata

.include <bsd.port.mk>
