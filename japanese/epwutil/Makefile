# New ports collection makefile for:	epwutil
# Date created:		22 January 1999
# Whom:			Kazutoki TAKAMUNE <takamune@avrl.mei.co.jp>
#
# $FreeBSD$
#

PORTNAME=	epwutil
PORTVERSION=	1.1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/epwutil/

MAINTAINER=	takamune2004@yahoo.co.jp
COMMENT=	Utilities to manage Japanese EPWING or Electric-Book based CD-ROM

MAKEFILE=	makefile.unx
MANLANG=	ja

EPWPROGS=	bookinfo catdump squeeze
EPWDOCS=	epwutil.doc
EPWDOCDIR=	share/doc/epwutil

do-install:
.for file in ${EPWPROGS}
	cd ${WRKSRC};\
	${INSTALL_PROGRAM} ${file} ${PREFIX}/bin;\
	${INSTALL_MAN} ${file}.man ${MANPREFIX}/man/${MANLANG}/cat1/${file}.1
.if !defined(NOMANCOMPRESS)
	${GZIP_CMD} ${MANPREFIX}/man/${MANLANG}/cat1/${file}.1
.endif
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${EPWDOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${EPWDOCS} ${PREFIX}/${EPWDOCDIR}
.endif

post-install:
.for file in ${EPWPROGS}
	${ECHO_CMD} man/${MANLANG}/cat1/${file}.1${MANEXT} >> ${TMPPLIST}
.endfor
.if !defined(NOPORTDOCS)
	${ECHO_CMD} ${EPWDOCDIR}/${EPWDOCS} >> ${TMPPLIST}
	${ECHO_CMD} "@dirrm ${EPWDOCDIR}" >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
