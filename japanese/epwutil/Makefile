# New ports collection makefile for:	epwutil
# Version required:	1.0
# Date created:		22 January 1999
# Whom:			Kazutoki TAKAMUNE <takamune@avrl.mei.co.jp>
#
# $FreeBSD$
#

DISTNAME=	epwutil-1.0
PKGNAME=	ja-epwutil-1.0
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.nerimadors.or.jp/pub/epwutil/

MAINTAINER=	takamune@avrl.mei.co.jp

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile.unx
MANLANG=	ja

EPWPROGS=	bookinfo catdump squeeze
EPWDOCS=	epwutil.doc
EPWDOCDIR=	${PREFIX}/share/doc/epwutil

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ${EPWPROGS} ${PREFIX}/bin
.for file in ${EPWPROGS}
	cd ${WRKSRC};\
	${INSTALL_MAN} ${file}.man ${MANPREFIX}/man/${MANLANG}/cat1/${file}.1
.if !defined(NOMANCOMPRESS)
	${GZIP_CMD} -9nf ${MANPREFIX}/man/${MANLANG}/cat1/${file}.1
.endif
.endfor
	@${MKDIR} ${EPWDOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${EPWDOCS} ${EPWDOCDIR}

.include <bsd.port.mk>
