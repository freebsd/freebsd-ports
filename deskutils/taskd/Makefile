# Created by: gahr
# $FreeBSD$

PORTNAME=	taskd
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://taskwarrior.org/download/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Multi-user server for taskwarrior

LICENSE=	MIT

LIB_DEPENDS=	libgnutls.so:security/gnutls
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:outsource compiler:c++11-lib shebangfix
SHEBANG_FILES=	demo/client/case* \
		demo/client/malformed* \
		demo/client/run \
		demo/client/setup \
		demo/server/run \
		demo/server/setup \
		mon/create \
		scripts/setup_server.bash \
		src/taskdctl \
		pki/generate \
		pki/generate.ca \
		pki/generate.client \
		pki/generate.crl \
		pki/generate.server

CFLAGS+=	-g -O0

PLIST_FILES=	bin/taskd \
		bin/taskdctl \
		man/man1/taskd.1.gz \
		man/man1/taskdctl.1.gz \
		man/man5/taskdrc.5.gz \
		share/taskd/README \
		share/taskd/generate \
		share/taskd/generate.ca \
		share/taskd/generate.client \
		share/taskd/generate.crl \
		share/taskd/generate.server \
		share/taskd/vars

PORTDOCS=	*

post-install:
	(cd ${WRKSRC}/pki && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
.for s in generate generate.ca generate.client generate.crl generate.server
	${CHMOD} 755 ${STAGEDIR}${DATADIR}/${s}
.endfor

.include <bsd.port.mk>
