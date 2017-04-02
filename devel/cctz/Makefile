# $FreeBSD$

PORTNAME=	cctz
PORTVERSION=	2.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	z7dr6ut7gs@snkmail.com
COMMENT=	C++ library for handling dates, times, and time zones

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

GH_ACCOUNT=	google
USE_GITHUB=	yes
USES=		compiler:c++11-lib gmake

MAKE_ARGS+=	CXX=${CXX} \
		EXTRA_CPPFLAGS="-D_POSIX_C_SOURCE=201112L -D_XOPEN_SOURCE=600"

PLIST_FILES=	include/civil_time.h \
		include/civil_time_detail.h \
		include/time_zone.h lib/libcctz.a
PORTDOCS=	README.md

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
