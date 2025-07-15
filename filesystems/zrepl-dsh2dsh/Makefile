PORTNAME=	zrepl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.10
CATEGORIES=	filesystems sysutils
PKGNAMESUFFIX=	-${GH_ACCOUNT}

MAINTAINER=	dsh@bamus.cz
COMMENT=	ZFS dataset replication tool (fork with more features)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	dsh2dsh

GO_MOD_DIST=	github
GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}
_BUILD_XFLAGS=	version.${PORTNAME}Version=${DISTVERSIONFULL}
GO_BUILDFLAGS=	-ldflags "${STRIP} ${_BUILD_XFLAGS:S!^!-X ${GO_MODULE}/internal/!}"

CONFLICTS_INSTALL=	${PORTNAME}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/local/etc/${PORTNAME}|${ETCDIR}|g' \
		-e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/dist/freebsd/etc/periodic/daily/${PORTNAME} \
		${WRKSRC}/dist/freebsd/etc/periodic/weekly/500.${PORTNAME} \
		${WRKSRC}/dist/freebsd/etc/rc.d/${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d \
		${STAGEDIR}${PREFIX}/etc/periodic/daily \
		${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${WRKSRC}/dist/freebsd/etc/rc.d/${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} \
		${WRKSRC}/dist/freebsd/etc/newsyslog.conf.d/${PORTNAME}.conf \
		${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf
	${INSTALL_DATA} \
		${WRKSRC}/dist/freebsd/etc/${PORTNAME}/keys.yaml \
		${STAGEDIR}${ETCDIR}/keys.yaml.sample
	${INSTALL_DATA} ${WRKSRC}/dist/freebsd/etc/${PORTNAME}/${PORTNAME}.yml \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.yml.sample
	${INSTALL_SCRIPT} \
		${WRKSRC}/dist/freebsd/etc/periodic/daily/${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/periodic/daily/${PORTNAME}
	${INSTALL_SCRIPT} \
		${WRKSRC}/dist/freebsd/etc/periodic/weekly/500.${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/periodic/weekly/500.${PORTNAME}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/hooks
	(cd ${WRKSRC}/internal/config/samples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_DATA} \
		${WRKSRC}/dist/grafana/grafana-prometheus-${PORTNAME}.json \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
