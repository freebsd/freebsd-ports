# Created by: Janni <jannisan@t-online.de>
# $FreeBSD$

PORTNAME=	Atlas
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/${PORTNAME}-C%2B%2B%20%28protocol%20lib%29/${PORTVERSION}
DISTNAME=	${PORTNAME}-C++-${PORTVERSION:S/.r/rc/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	C++ reference implementation of the Atlas protocol

OPTIONS_DEFINE=	DOCS

PKGNAMESUFFIX=	-devel
GNU_CONFIGURE=	yes
USES=	pathfix compiler:c++11-lang
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	YES
USE_BZIP2=	YES
USE_GCC=	yes
MAKE_ARGS=	docdir=${DOCSDIR}
CONFIGURE_ARGS+=--program-transform-name=

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in README COPYING AUTHORS THANKS NEWS ChangeLog TODO HACKING ROADMAP
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
