PORTNAME=	libblkid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.41
CATEGORIES=	filesystems

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Library to identify block devices (disks) as to their content
WWW=		https://github.com/util-linux/util-linux

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Documentation/licenses/COPYING.BSD-3-Clause

USES=		bison meson pkgconfig tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	util-linux
GH_PROJECT=	util-linux

USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
# disable all Meson features because the project has gazillion of them and we only need few
MESON_ARGS=	--auto-features=disabled \
		-Db_lundef=false \
		-Dprogram-tests=false \
		-Dallow-32bit-time=true \
		-Dbuild-libblkid=enabled \
		-Dbuild-libsmartcols=enabled # dependency of libblkid

OPTIONS_DEFINE=		MANPAGES
MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor

.include <bsd.port.mk>
