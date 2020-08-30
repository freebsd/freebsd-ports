# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	vda2fbd
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	converters cad
MASTER_SITES=	http://www.dhondt.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Add-on converter for CalculiX

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../LICENSE

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" YACC="${YACC}"
WRKSRC_SUBDIR=	src

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

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
