# Created by: Keith Gaughan <k@stereochro.me>
# $FreeBSD$

PORTNAME=	utf8cpp
PORTVERSION=	2.3.4
CATEGORIES=	devel
MASTER_SITES=	SF/utfcpp/${PORTNAME:tl}_2x/Release%20${PORTVERSION}/
DISTNAME=	utf8_v${PORTVERSION:S/./_/g}

MAINTAINER=	k@stereochro.me
COMMENT=	Simple, portable, lightweight library for handling UTF-8 strings

LICENSE=	BSL

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	include/utf8.h \
		include/utf8/checked.h \
		include/utf8/core.h \
		include/utf8/unchecked.h

do-install:
	(cd ${WRKSRC}/source; ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include)

.include <bsd.port.mk>
