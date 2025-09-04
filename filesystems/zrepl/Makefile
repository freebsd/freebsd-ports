PORTNAME=	zrepl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
PORTREVISION=	17
CATEGORIES=	filesystems sysutils

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	ZFS dataset replication tool
WWW=		https://zrepl.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules ncurses
USE_RC_SUBR=	zrepl
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		${STRIP} -w\
		-X ${GO_MODULE}/version.${PORTNAME}Version=${DISTVERSIONFULL}"

SUB_FILES=	pkg-message 500.zrepl

OPTIONS_DEFINE=		EXAMPLES MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	sphinx-multiversion:textproc/py-sphinx-multiversion-zrepl@${PY_FLAVOR}
MANPAGES_USES=		gmake python:build
MANPAGES_PLIST_FILES=	share/man/man1/zrepl.1.gz

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

post-build-MANPAGES-on:
	@${MAKE_CMD} -C ${WRKSRC}/docs SPHINXBUILD=sphinx-build-${PYTHON_VER} man

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d \
		${STAGEDIR}${PREFIX}/etc/syslog.d \
		${STAGEDIR}/var/run/zrepl
	${INSTALL_DATA} ${FILESDIR}/newsyslog.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf
	${INSTALL_DATA} ${FILESDIR}/syslog.conf ${STAGEDIR}${EXAMPLESDIR}/syslog.conf
	${INSTALL_DATA} ${FILESDIR}/zrepl.yml ${STAGEDIR}${ETCDIR}/zrepl.yml.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${WRKDIR}/500.zrepl \
		${STAGEDIR}${PREFIX}/etc/periodic/weekly/500.zrepl

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/hooks
	(cd ${WRKSRC}/config/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_DATA} ${WRKSRC}/dist/grafana/grafana-prometheus-zrepl.json ${STAGEDIR}${EXAMPLESDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/zrepl.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
