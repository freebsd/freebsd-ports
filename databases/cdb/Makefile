PORTNAME=	cdb
DISTVERSION=	20251021
CATEGORIES=	databases
MASTER_SITES=	https://cdb.cr.yp.to/

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Fast lookup database library & utilities
WWW=		https://cdb.cr.yp.to/

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/doc/license.md

ALL_TARGET=	it

CFLAGS_amd64=	-fPIC

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-configure:
	@${MV} ${WRKSRC}/conf-home ${WRKSRC}/conf-home.orig
	${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home
	@${MV} ${WRKSRC}/conf-cc ${WRKSRC}/conf-cc.orig
	${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${MV} ${WRKSRC}/conf-ld ${WRKSRC}/conf-ld.orig
	${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} cdbdump cdbget cdbmake cdbstats \
		cdbtest cdb64dump cdb64get cdb64make cdb64stats cdb64test \
		${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_SCRIPT} cdbmake-12 cdbmake-sv \
		cdb64make-12 cdb64make-sv ${STAGEDIR}${PREFIX}/bin

# cdb.3 conflicts with databases/tinycdb, so do not install man pages in MANDIRS.
do-install-DOCS-on:
	${GZIP_CMD} ${WRKSRC}/doc/man/*
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "*" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
