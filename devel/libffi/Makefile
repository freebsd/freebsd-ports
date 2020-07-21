# Created by: Horance Chou <horance@freedom.ie.cycu.edu.tw>
# $FreeBSD$

PORTNAME=	libffi
PORTVERSION=	3.3
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/${PORTNAME}

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	01a75ed76ea7e57f1b7a5c183e2b1e890e6aa0fd.patch:-p1

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Foreign Function Interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	runtest:misc/dejagnu

USES=		compiler:c11 libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-multi-os-directory
INSTALL_TARGET=	install-strip
INFO=		libffi
TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} -e 's| -Wno-psabi||g' \
		${WRKSRC}/testsuite/lib/libffi.exp

.include <bsd.port.mk>
