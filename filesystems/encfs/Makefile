PORTNAME=	encfs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.5
PORTREVISION=	12
CATEGORIES=	filesystems
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Encrypted pass-through FUSE filesystem
WWW=		https://vgough.github.io/encfs/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libeasyloggingpp.so:devel/easyloggingpp \
		libtinyxml2.so:textproc/tinyxml2

USES=		cmake compiler:c++11-lib cpe fuse pkgconfig ssl
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	vgough

CMAKE_OFF=	BUILD_UNIT_TESTS \
		USE_INTERNAL_EASYLOGGING \
		USE_INTERNAL_TINYXML
CMAKE_ARGS=	-DEASYLOGGINGPP_LIBRARY:PATH=${LOCALBASE}/lib/libeasyloggingpp.so

OPTIONS_DEFINE=	MANPAGES NLS
OPTIONS_DEFAULT=	BUNDLED_TINYXML MANPAGES
OPTIONS_SUB=	yes

MANPAGES_DESC=	Install manpages (requires Perl 5)
MANPAGES_USES=	perl5
MANPAGES_USE=	perl5=build

NLS_USES=	gettext
NLS_CMAKE_BOOL=	ENABLE_NLS

.include <bsd.port.mk>
