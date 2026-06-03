PORTNAME=	sch-rnd
DISTVERSION=	1.0.10
CATEGORIES=	cad
MASTER_SITES=	http://www.repo.hu/projects/${PORTNAME}/releases/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Simple, modular, scriptable schematics editor
WWW=		http://www.repo.hu/projects/sch-rnd/

LICENSE=	LGPL21
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

TEST_TARGET=	test

BINARY_ALIAS=	make=${MAKE_CMD}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
.for f in bin/sch-rnd lib/sch-rnd/minuid
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/$f
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/sch-rnd/plugins/*.so

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
