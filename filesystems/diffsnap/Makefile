PORTNAME=	diffsnap
DISTVERSION=	1.0.1
CATEGORIES=	filesystems

MAINTAINER=	josephsaathoff@gmail.com
COMMENT=	Create ZFS snapshots based on data write thresholds
WWW=		https://github.com/joe81tx/diffsnap

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le riscv64

USE_GITHUB=	yes
GH_ACCOUNT=	joe81tx

MAKE_ARGS+=	BUILD_SHA=portbld

PLIST_FILES=	"@dir etc/cron.d" \
		"@sample etc/diffsnap.conf.sample" \
		"@sample etc/diffsnap.cron.sample etc/cron.d/diffsnap" \
		"@sample etc/newsyslog.conf.d/diffsnap.conf.sample" \
		sbin/diffsnap

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/diffsnap

.include <bsd.port.mk>
