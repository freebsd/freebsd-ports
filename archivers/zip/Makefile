# New ports collection makefile for:    zip
# ftp://ftp.info-zip.org/pub/infozip/Info-ZIP.html
# Date created:		22 Dec 1994
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	zip
PORTVERSION=	2.3
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.uu.net/pub/archiving/zip/src/ \
		${MASTER_SITE_TEX_CTAN:S,%SUBDIR%,tools/zip/info-zip/src/,}
DISTFILES=	zip23${EXTRACT_SUFX} ${ZCRYPT_SRC}
EXTRACT_ONLY=	zip23${EXTRACT_SUFX}

MAINTAINER=	ache@FreeBSD.org
COMMENT=	Create/update ZIP files compatible with pkzip

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

ZCRYPT_SRC=	zcrypt29-exportable.zip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	unix/Makefile
MAKE_FLAGS=	LOCAL_ZIP="-DUSE_CRYPT" -f
ALL_TARGET=	generic
MAN1=		zip.1

post-extract:
	unzip -q -aa -o ${_DISTDIR}${ZCRYPT_SRC} -d ${WRKSRC} -x WHERE

do-install:
.for file in zip zipcloak zipnote zipsplit
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/zip.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
