# $FreeBSD$

PORTNAME=	cctz
PORTVERSION=	2.2
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	z7dr6ut7gs@snkmail.com
COMMENT=	C++ library for handling dates, times, and time zones

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

GH_ACCOUNT=	google
USES=		compiler:c++11-lib gmake
USE_GITHUB=	yes

MAKE_ARGS+=	CXX=${CXX} \
		EXTRA_CPPFLAGS="-D_POSIX_C_SOURCE=201112L -D_XOPEN_SOURCE=600"

PLIST_FILES=	include/cctz/civil_time.h \
		include/cctz/civil_time_detail.h \
		include/cctz/time_zone.h \
		include/cctz/zone_info_source.h \
		lib/libcctz.a
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
