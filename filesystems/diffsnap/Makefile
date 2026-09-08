PORTNAME=		diffsnap
DISTVERSION=	1.0
CATEGORIES=		filesystems

MAINTAINER=		josephsaathoff@gmail.com
COMMENT=		Create ZFS snapshots based on data write thresholds
WWW=			https://github.com/joe81tx/diffsnap

LICENSE=		BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=		yes
GH_ACCOUNT=		joe81tx

PLIST_FILES=	sbin/diffsnap \
				"@sample etc/newsyslog.conf.d/diffsnap.conf.sample" \
				"@sample etc/diffsnap.conf.sample" \
				"@sample etc/diffsnap.cron.sample etc/cron.d/diffsnap"

MAKE_ARGS+=		BUILD_SHA=portbld

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/diffsnap

.include <bsd.port.mk>
