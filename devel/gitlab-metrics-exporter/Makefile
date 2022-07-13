# Created by: Matthias Fechner <mfechner@FreeBSD.org>

PORTNAME=	gitlab-metrics-exporter
PORTVERSION=	0.1.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab Metrics Exporter (GME) is Ruby Prometheus exporter

LICENSE=	MIT

USES=		go:modules
GO_MODULE=	gitlab.com/gitlab-org/gitlab-metrics-exporter


GO_TARGET=	./cmd/srv

PLIST_FILES+=	bin/srv

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/srv ${STAGEDIR}${PREFIX}/bin/srv

.include <bsd.port.mk>

