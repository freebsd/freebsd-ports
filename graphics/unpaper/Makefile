# New ports collection makefile for:	unpaper
# Date created:		01 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unpaper
DISTVERSION=	0_2
CATEGORIES=	graphics
MASTER_SITES=	BERLIOS
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Post-processing tool for scanned sheets of paper

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|doc/||g' ${WRKSRC}/unpaper.html

do-build:
	@${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/src/${PORTNAME}.c -lm

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/unpaper.html ${WRKSRC}/readme.txt ${DOCSDIR}/
	@${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}/
.endif

.include <bsd.port.mk>
