# New ports collection makefile for:    omi
# Date created:		19 August 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	omi
PORTVERSION=	20030719
CATEGORIES=	ftp
MASTER_SITES=	http://www.secnetix.de/~olli/distfiles/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/
#	http://dorifer.heim3.tu-clausthal.de/~olli/omi/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	"mirror" subtrees of FTP servers

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	freebsd

pre-patch:
	${REINPLACE_CMD} -E -e "s@^(OPTFLAGS).*@\1=${CFLAGS}@" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omi ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 755 -o ${DOCOWN} -g ${DOCGRP} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/BSD-COPYRIGHT ${DOCSDIR}/
.endif

.include <bsd.port.mk>
