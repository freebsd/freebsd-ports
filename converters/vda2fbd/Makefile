# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	vda2fbd
PORTVERSION=	1.0
CATEGORIES=	converters cad
MASTER_SITES=	http://www.dhondt.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Add-on converter for CalculiX

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../LICENSE

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" YACC="${YACC}"
WRKSRC_SUBDIR=	src

PORTDOCS=	model.ps.gz
PLIST_FILES=	bin/vda2fbd

OPTIONS_DEFINE=	DOCS

post-build:
	cd ${WRKSRC}/../doc && ${GZIP_CMD} -c model.ps > model.ps.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vda2fbd ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/model.ps.gz ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
