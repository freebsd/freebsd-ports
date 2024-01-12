PORTNAME=	lv2lint
DISTVERSION=	0.16.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://git.open-music-kontrollers.ch/lv2/lv2lint/snapshot/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Check whether a given LV2 plugin is up to the specification
WWW=		https://open-music-kontrollers.ch/lv2/lv2lint/

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSES/Artistic-2.0.txt

BROKEN_riscv64=	ld: error: lto.tmp: cannot link object files with different floating-point ABI

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		curl>0:ftp/curl \
		libelf>0:devel/libelf
LIB_DEPENDS=	liblilv-0.so:audio/lilv
RUN_DEPENDS=	curl>0:ftp/curl \
		libelf>0:devel/libelf

USES=		compiler:c++11-lang meson pkgconfig tar:xz

PLIST_FILES=	bin/lv2lint \
		share/man/man1/lv2lint.1.gz

.include <bsd.port.mk>
