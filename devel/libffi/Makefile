# Created by: Horance Chou <horance@freedom.ie.cycu.edu.tw>
# $FreeBSD$

PORTNAME=	libffi
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/${PORTNAME}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Foreign Function Interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	runtest:misc/dejagnu

USES=		libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
INFO=		libffi
PLIST_SUB=	PORTVERSION=${PORTVERSION}
TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} -e 's| -Wno-psabi||g' \
		${WRKSRC}/testsuite/lib/libffi.exp

post-install:
	@${LN} -sf ../lib/libffi-${PORTVERSION}/include/ffi.h \
	    ${STAGEDIR}${PREFIX}/include/
	@${LN} -sf ../lib/libffi-${PORTVERSION}/include/ffitarget.h \
	    ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
