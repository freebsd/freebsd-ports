# New ports collection makefile for:   abcmidi
# Date created:			10 March 2002
# Whom:				Sue Blake <sue@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abcmidi
PORTVERSION=	36
CATEGORIES=	audio
MASTER_SITES=	http://abc.sourceforge.net/abcMIDI/
DISTNAME=	abcMIDI

MAINTAINER=	sue@FreeBSD.org

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
MAKEFILE=	unix.mak

DOCS=	abcguide.txt demo.abc readme.txt yaps.txt

pre-patch:
.for file in ${DOCS} ${MAKEFILE}
	@(cd ${WRKSRC} ; ${MV} -f ${file} ${file}.orig ; \
		${TR} -d '\r' < ${file}.orig > ${file})
.endfor
	@${REINPLACE_CMD} -e "s,^CC,#CC,g" -e "s,^CFLAGS=,CFLAGS+=,g" \
		${WRKSRC}/${MAKEFILE}

do-install:
.for file in abc2abc abc2midi mftext midi2abc yaps
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
