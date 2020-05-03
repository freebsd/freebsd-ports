# Created by: J.F. Dockes
# $FreeBSD$

PORTNAME=	xapian-core
PORTVERSION=	1.2.25
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMESUFFIX=	12

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Probabilistic text search database engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix tar:xz

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	*

CONFLICTS_INSTALL=	xapian-core xapian-core10

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	DOCS SSE2
SSE2_DESC=	Use SSE2 for floating point

SSE2_CONFIGURE_ENABLE=	sse

post-install:
.for file in copydatabase delve quest
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/${file} ${STAGEDIR}${PREFIX}/bin/xapian-${file}
.endfor

.include <bsd.port.mk>
