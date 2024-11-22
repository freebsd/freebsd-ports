PORTNAME=	zrepl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.2
CATEGORIES=	filesystems sysutils
PKGNAMESUFFIX=	-dsh2dsh

MAINTAINER=	dsh@bamus.cz
COMMENT=	ZFS dataset replication tool (fork with more features)
WWW=		https://github.com/dsh2dsh/${PORTNAME}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules ncurses

GO_MODULE=	github.com/dsh2dsh/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "${STRIP} -w -X github.com/dsh2dsh/${PORTNAME}/internal/version.${PORTNAME}Version=${DISTVERSIONFULL}"

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
