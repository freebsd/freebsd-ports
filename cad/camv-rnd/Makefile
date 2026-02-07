PORTNAME=	camv-rnd
DISTVERSION=	1.1.6
CATEGORIES=	cad
MASTER_SITES=	http://www.repo.hu/projects/${PORTNAME}/releases/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Small, flexible viewer for PCB-related CAM file formats
WWW=		http://www.repo.hu/projects/camv-rnd/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfungw.so:devel/fungw \
		libgenht.so:devel/genht \
		librnd-hid.so:cad/librnd

USES=		gmake tar:bz2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${WITH_DEBUG:D--debug} \
		--CC=${CC} \
		--CFLAGS='${CFLAGS}' \
		--LDFLAGS='${LDFLAGS}'

BINARY_ALIAS=	make=${MAKE_CMD}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/camv-rnd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/camv-rnd/plugins/*.so

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
