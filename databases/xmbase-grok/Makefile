# New ports collection makefile for:	xmbase-grok
# Date created:		Sat Aug 30 13:29:42 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	xmbase-grok
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://www.sourcefiles.org/Databases/Relational/ \
		http://fossies.org/unix/misc/old/ \
		ftp://grok.ftp.fu-berlin.de/
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical Resource Organizer Kit

BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src

USE_XORG=	x11 xt
USE_MOTIF=	yes
MAKE_ENV=	MYCC="${CC}" DEBUG="${CFLAGS}" YO="" INCDIR="" \
		GBIN="${PREFIX}/bin" GLIB="${DATADIR}" \
		CF="-I${LOCALBASE}/include" LF="${MOTIFLIB} -lXt -lX11 -lm"
MAN1=		grok.1
MAKE_JOBS_SAFE=	yes

DATADIR=	${PREFIX}/lib/X11/xmbase-grok

pre-patch:
	@${REINPLACE_CMD} -e 's|^GBIN =|#GBIN =|g ; \
		 s|^GLIB =|#GLIB =|g ; \
		 s|^DEBUG =|#DEBUG =|g' ${BUILD_WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/grok ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/grok.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/misc/grok.hlp ${DATADIR}
	@${MKDIR} ${DATADIR}/grokdir
	@(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${DATADIR}/grokdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
