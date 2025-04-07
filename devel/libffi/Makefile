PORTNAME=	libffi
DISTVERSION=	3.4.7
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	fe203ffbb2bd7f93a86013d341aa767a406150bc.patch:-p1

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Foreign Function Interface
WWW=		https://sourceware.org/libffi/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	runtest:misc/dejagnu

USES=		compiler:c11 cpe libtool pathfix
CPE_VENDOR=	libffi_project
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-multi-os-directory
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

LDFLAGS+=	-Wl,--undefined-version

INFO=		libffi

post-patch:
	@${REINPLACE_CMD} -e 's| -Wno-psabi||g' \
		${WRKSRC}/testsuite/lib/libffi.exp

.include <bsd.port.mk>
