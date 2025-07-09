PORTNAME=	influxdb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.10
PORTREVISION=	30
CATEGORIES=	databases net-mgmt

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Open-source distributed time series database
WWW=		https://influxdata.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.5.0:sys

CPE_VENDOR=	influxdata

USE_RC_SUBR=	influxd

GO_MODULE=	github.com/influxdata/influxdb
GO_TARGET=	./cmd/influx ./cmd/influx_inspect ./cmd/influx_stress \
		./cmd/influxd

GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSION}"

SUB_LIST=	INFLUXD_DBDIR=${INFLUXD_DBDIR} \
		INFLUXD_GROUP=${INFLUXD_GROUP} \
		INFLUXD_LOGDIR=${INFLUXD_LOGDIR} \
		INFLUXD_PIDDIR=${INFLUXD_PIDDIR} \
		INFLUXD_USER=${INFLUXD_USER}

USERS=		${INFLUXD_USER}
GROUPS=		${INFLUXD_GROUP}

PLIST_SUB=	INFLUXD_DBDIR=${INFLUXD_DBDIR} \
		INFLUXD_GROUP=${INFLUXD_GROUP} \
		INFLUXD_LOGDIR=${INFLUXD_LOGDIR} \
		INFLUXD_PIDDIR=${INFLUXD_PIDDIR} \
		INFLUXD_USER=${INFLUXD_USER}

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_USES=		gmake
MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			docbook-xml>0:textproc/docbook-xml \
			xmlto:textproc/xmlto

INFLUXD_DBDIR=	/var/db/${PORTNAME}/
INFLUXD_LOGDIR=	/var/log/${PORTNAME}/
INFLUXD_PIDDIR=	/var/run/${PORTNAME}/

INFLUXD_USER=	influxd
INFLUXD_GROUP=	influxd

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD"
SUB_LIST+=	INFLUXD_LOGCMD="daemon"
.else
SUB_LIST+=	INFLUXD_LOGCMD="logger"
.endif

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

do-build-MANPAGES-on:
	@cd ${WRKSRC}/man && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install:
	${MKDIR} ${STAGEDIR}${INFLUXD_DBDIR} \
	${STAGEDIR}${INFLUXD_PIDDIR} \
	${STAGEDIR}${INFLUXD_LOGDIR}
	@${SED} -i .bak -e \
		"s|/var/lib/influxdb|/var/db/influxdb|g" \
		${WRKSRC}/etc/config.sample.toml
	${INSTALL_DATA} \
		${WRKSRC}/etc/config.sample.toml \
		${STAGEDIR}${PREFIX}/etc/influxd.conf.sample

.include <bsd.port.post.mk>
