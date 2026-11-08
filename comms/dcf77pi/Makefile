PORTNAME=	dcf77pi
PORTVERSION=	3.7.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	comms
FJ_ACCOUNT=	rene0

MAINTAINER=	rene@FreeBSD.org
COMMENT=	DCF77 receiver/logger/analyzer and library for the Raspberry Pi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

DEPRECATED=	No development for years, consider using misc/radio_datetime_analyzer instead
EXPIRATION_DATE=2026-12-31

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		ncurses pkgconfig
USE_FORGEJO=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

PATCH_STRIP=	-p1
PORTDOCS=	CHANGELOG.md README.md receiver.svg

OPTIONS_DEFINE=		DOCS DOXYGEN
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	all doxygen
DOXYGEN_INSTALL_TARGET=	install-doxygen
DOXYGEN_PORTDOCS=	html/*

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.md # do not install twice
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
