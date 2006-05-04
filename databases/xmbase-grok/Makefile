# New ports collection makefile for:	xmbase-grok
# Date created:		Sat Aug 30 13:29:42 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	xmbase-grok
PORTVERSION=	1.5
CATEGORIES=	databases
MASTER_SITES=	ftp://grok.ftp.fu-berlin.de/ \
		ftp://bitrot.de/pub/grok/
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical Resource Organizer Kit

BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src

USE_X_PREFIX=	yes
USE_MOTIF=	yes
MAKE_ENV=	MYCC="${CC}" DEBUG="${CFLAGS}" YO="" INCDIR="" \
		GBIN="${PREFIX}/bin" GLIB="${DATADIR}" \
		CF="-I${X11BASE}/include" LF="${MOTIFLIB} -lXt -lX11 -lm"
MAN1=		grok.1

DATADIR=	${PREFIX}/lib/X11/xmbase-grok

pre-patch:
	@${REINPLACE_CMD} -e 's|^GBIN =|#GBIN =|g ; \
		 s|^GLIB =|#GLIB =|g ; \
		 s|^DEBUG =|#DEBUG =|g' ${BUILD_WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/grok ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/grok.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/misc/grok.hlp ${DATADIR}
	@${MKDIR} ${DATADIR}/grokdir
	@${TAR} -C ${WRKSRC}/demo -cf - . | \
		${TAR} -C ${DATADIR}/grokdir -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/grokdir
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
