# Created by: Mike Buchanon <buchanon@msu.edu>
# $FreeBSD$

PORTNAME=	bcpp
PORTVERSION=	20120318
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/bcpp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility similar to indent for C++ code

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

CFLAGS+=	-DBCPP_CONFIG_DIR=\\\"${PREFIX}/etc/${PORTNAME}\\\"

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/code/bcpp.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/code/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/code/${PORTNAME}.cfg \
		${PREFIX}/etc/${PORTNAME}.cfg.sample
.if !exists(${PREFIX}/etc/${PORTNAME}.cfg)
	cd ${PREFIX}/etc && ${CP} -p ${PORTNAME}.cfg.sample ${PORTNAME}.cfg
.endif
.if ${PORT_OPTIONS:MDOCS}
	@@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/txtdocs/hirachy.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/txtdocs/manual.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
