PORTNAME=	zfs-snap-diff
PORTVERSION=	1.1.3
DISTVERSIONPREFIX=	v
PORTREVISION=	28
CATEGORIES=	filesystems sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	View ZFS snapshot differences via a web browser
WWW=		https://github.com/j-keck/zfs-snap-diff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	j-keck
GH_TUPLE=	BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		j-keck:go-diff:v1.0.0:j_keck_go_diff/vendor/github.com/j-keck/go-diff \
		j-keck:plog:v0.7.0:j_keck_plog/vendor/github.com/j-keck/plog

PLIST_FILES=	bin/zfs-snap-diff

GO_BUILDFLAGS=	-ldflags="-X main.version=${DISTVERSIONPREFIX}${PORTVERSION}"

GO_TARGET=	./cmd/zfs-snap-diff

.include <bsd.port.mk>
