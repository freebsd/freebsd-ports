PORTNAME=	gitlab-metrics-exporter
PORTVERSION=	0.1.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab Metrics Exporter (GME) is Ruby Prometheus exporter
WWW=		https://gitlab.com/gitlab-org/gitlab-metrics-exporter

LICENSE=	MIT

USES=		go:modules
GO_MODULE=	gitlab.com/gitlab-org/gitlab-metrics-exporter

GO_TARGET=	./cmd/srv

PLIST_FILES+=	bin/srv

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/srv ${STAGEDIR}${PREFIX}/bin/srv

.include <bsd.port.mk>
