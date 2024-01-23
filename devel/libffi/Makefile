PORTNAME=	libffi
DISTVERSION=	3.4.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Foreign Function Interface
WWW=		https://sourceware.org/libffi/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	runtest:misc/dejagnu

USES=		compiler:c11 cpe libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CPE_VENDOR=	libffi_project

CONFIGURE_ARGS=	--disable-multi-os-directory
INSTALL_TARGET=	install-strip
INFO=		libffi
TEST_TARGET=	check

LDFLAGS+=	-Wl,--undefined-version

post-patch:
	@${REINPLACE_CMD} -e 's| -Wno-psabi||g' \
		${WRKSRC}/testsuite/lib/libffi.exp

.include <bsd.port.mk>
