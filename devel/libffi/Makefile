# Created by: Horance Chou <horance@freedom.ie.cycu.edu.tw>

PORTNAME=	libffi
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/${PORTNAME}

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES+=	01a75ed76ea7e57f1b7a5c183e2b1e890e6aa0fd.diff:-p1
# This patch is for configure.ac.
# A local patch against configure has been created in files/patch-configure.
#PATCHFILES+=	8c50837f0b58ba5b2bcb1b424a2a4bfa01559fb2.diff:-p1

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Foreign Function Interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	runtest:misc/dejagnu

USES=		compiler:c11 cpe libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPE_VENDOR=	libffi_project

CONFIGURE_ARGS=	--disable-multi-os-directory
INSTALL_TARGET=	install-strip
INFO=		libffi
TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} -e 's| -Wno-psabi||g' \
		${WRKSRC}/testsuite/lib/libffi.exp

.include <bsd.port.mk>
