# Created by: J.F. Dockes
# $FreeBSD$

PORTNAME=	xapian-core
PORTVERSION=	1.2.17
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Probabilistic text search database engine

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS SSE2
SSE2_DESC=	Use SSE2 for floating point

PORTSCOUT=	limitw:1,even

GNU_CONFIGURE=	yes
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
USE_LDCONFIG=	yes
USES=		tar:xz

PORTDOCS=	*

SSE2_CONFIGURE_ENABLE=	sse

post-install:
.for file in copydatabase delve quest
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/${file} ${STAGEDIR}${PREFIX}/bin/xapian-${file}
.endfor

.include <bsd.port.mk>
