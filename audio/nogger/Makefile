# New ports collection makefile for:	nogger
# Date created:				2002-10-27
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	nogger
PORTVERSION=	0.8.2
CATEGORIES=	audio
MASTER_SITES=	http://www.efd.lth.se/~d00jkr/nogger/

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20 \
		vorbis.2:${PORTSDIR}/audio/libvorbis

PLIST=		${WRKDIR}/plist
USE_GMAKE=	y
ALL_TARGET=	nogger

pre-install:
	${ECHO_CMD} bin/nogger > ${PLIST}
.ifndef(NOPORTDOCS)
.for ii in COPYING README Thanks
	${ECHO_CMD} share/doc/nogger/${ii} ${DOCSDIR}
.endfor
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nogger ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in COPYING README Thanks
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
