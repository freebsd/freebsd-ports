# New ports collection makefile for:	iperf
# Date Created:				20 May 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	iperf
PORTVERSION= 	1.6.5
CATEGORIES=	net
MASTER_SITES=	http://dast.nlanr.net/Projects/Iperf/
DISTNAME=	iperf-1.6.5-source

MAINTAINER=	smace@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_CDROM=	"can't charge a fee for the software"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iperf ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/iperf
.for file in README doc/index.html doc/jperf.gif doc/dast.gif \
		doc/lib.html doc/ui_license.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/iperf
.endfor
.endif

.include <bsd.port.mk>
