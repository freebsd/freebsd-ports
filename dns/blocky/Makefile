PORTNAME=	blocky
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod
DISTFILES=	go.mod:gomod

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Fast and lightweight DNS proxy as ad-blocker

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	0xERR0R
USE_RC_SUBR=	blocky

GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	main.go:${PREFIX}/sbin/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-w -s \
		-X github.com/0xERR0R/blocky/util.Version=${DISTVERSION} \
		-X github.com/0xERR0R/blocky/util.BuildTime=`date '+%Y%m%d-%H%M%S'`"

SUB_FILES=	pkg-message

post-install:
		${INSTALL_DATA} ${FILESDIR}/blocky-config.yml.sample ${STAGEDIR}${PREFIX}/etc/blocky-config.yml.sample

.include <bsd.port.mk>
