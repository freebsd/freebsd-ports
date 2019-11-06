# Created by: Mike Buchanon <buchanon@msu.edu>
# $FreeBSD$

PORTNAME=	bcpp
PORTVERSION=	20150811
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/bcpp/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Utility similar to indent for C++ code

BROKEN=		unfetchable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

CFLAGS+=	-DBCPP_CONFIG_DIR=\\\"${PREFIX}/etc/${PORTNAME}\\\"

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/code/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/code/${PORTNAME}.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/txtdocs/hirachy.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/txtdocs/manual.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
