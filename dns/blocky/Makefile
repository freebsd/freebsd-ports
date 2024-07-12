PORTNAME=	blocky
DISTVERSIONPREFIX=	v
DISTVERSION=	0.24
PORTREVISION=	2
CATEGORIES=	dns

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Fast and lightweight DNS proxy as ad-blocker
WWW=		https://0xerr0r.github.io/blocky/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules
USE_GITHUB=	yes
GH_ACCOUNT=	0xERR0R
USE_RC_SUBR=	blocky

GO_MOD_DIST=	github
GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	main.go:${PREFIX}/sbin/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-w -s \
		-X github.com/0xERR0R/blocky/util.Version=${DISTVERSION} \
		-X github.com/0xERR0R/blocky/util.BuildTime=`date '+%Y%m%d-%H%M%S'` \
		-X github.com/0xERR0R/blocky/util.Architecture=${ARCH}"

SUB_FILES=	pkg-message

PLIST_FILES=	"@sample etc/blocky-config.yml.sample" \
		sbin/blocky

post-install:
		${INSTALL_DATA} ${FILESDIR}/blocky-config.yml.sample ${STAGEDIR}${PREFIX}/etc/blocky-config.yml.sample

.include <bsd.port.mk>
