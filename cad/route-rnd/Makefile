PORTNAME=	route-rnd
DISTVERSION=	0.9.3
CATEGORIES=	cad
MASTER_SITES=	http://www.repo.hu/projects/${PORTNAME}/releases/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Flexible, modular autorouter for Printed Circuit Boards
WWW=		http://www.repo.hu/projects/route-rnd/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bz2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${WITH_DEBUG:D--debug} \
		--CC=${CC} \
		--CFLAGS='${CFLAGS}' \
		--LDFLAGS='${LDFLAGS}'

PLIST_FILES=	bin/route-rnd \
		share/man/man1/route-rnd.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/route-rnd

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
