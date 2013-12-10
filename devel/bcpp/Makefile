# Created by: Mike Buchanon <buchanon@msu.edu>
# $FreeBSD$

PORTNAME=	bcpp
PORTVERSION=	20120318
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/bcpp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility similar to indent for C++ code

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

CFLAGS+=	-DBCPP_CONFIG_DIR=\\\"${PREFIX}/etc/${PORTNAME}\\\"

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/code/bcpp.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/code/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/code/${PORTNAME}.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/txtdocs/hirachy.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/txtdocs/manual.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
