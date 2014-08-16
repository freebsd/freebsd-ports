# Created by: kuriyama
# $FreeBSD$

PORTNAME=	chasen
PORTVERSION=	2.4.5
PORTREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	SOURCEFORGE_JP/chasen-legacy/56305
PKGNAMESUFFIX=	-base

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Morphological Analysis System

BUILD_DEPENDS=	${LOCALBASE}/include/darts.h:${PORTSDIR}/devel/darts

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-darts=${LOCALBASE}/include ${ICONV_CONFIGURE_BASE}
USES=		iconv libtool
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/chasen/dic
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
