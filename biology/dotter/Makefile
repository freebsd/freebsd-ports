# ex:ts=8
# New ports collection makefile for:	dotter
# Date created:				11 Jan 2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	dotter
PORTVERSION=	20021204 # last modified date in FTP server
CATEGORIES=	biology
MASTER_SITES=	http://sonnhammer.sbc.su.se/download/software/dotter/
DISTNAME=	${PORTNAME}.LIN
EXTRACT_SUFX=	#
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	#

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A viewer for multiple sequence alignments

USE_LINUX=	yes
ONLY_FOR_ARCHS=	i386

BROKEN=		checksum mismatch

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME} bin/${DISTNAME}

do-install:
	${BRANDELF} -t Linux ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
	${PREFIX}/bin
	( cd ${PREFIX}/bin && ${LN} -s ${DISTNAME} ${PORTNAME} )

.include <bsd.port.mk>
