# Created by: J.F. Dockes
# $FreeBSD$

PORTNAME=	xapian-core
PORTVERSION=	1.4.13
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Probabilistic text search database engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	xapian-core10 xapian-core12

OPTIONS_DEFINE=	DOCS SSE2
SSE2_DESC=	Use SSE2 for floating point

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang libtool pathfix tar:xz

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

SSE2_CONFIGURE_ENABLE=	sse

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xapian-inspect ${STAGEDIR}${PREFIX}/bin/xapian-inspect

.include <bsd.port.mk>
