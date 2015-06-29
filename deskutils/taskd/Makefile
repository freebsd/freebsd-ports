# Created by: gahr
# $FreeBSD$

PORTNAME=	taskd
PORTVERSION=	1.1.0
CATEGORIES=	deskutils
MASTER_SITES=	http://taskwarrior.org/download/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Multi-user server for taskwarrior

LICENSE=	MIT

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		cmake:outsource compiler:c++11-lib shebangfix
SHEBANG_FILES=	demo/client/case* \
		demo/client/malformed* \
		demo/client/run \
		demo/client/setup \
		demo/server/run \
		demo/server/setup \
		mon/create \
		scripts/setup_server.bash \
		src/taskdctl

CFLAGS+=	-g -O0

PLIST_FILES=	bin/taskd \
		bin/taskdctl \
		man/man1/taskd.1.gz \
		man/man1/taskdctl.1.gz \
		man/man5/taskdrc.5.gz

PORTDOCS=	*

.include <bsd.port.mk>
