# New ports collection makefile for:	dmake
# Version required:     4.1
# Date created:		31 July 1995
# Whom:			nils@guru.ims.uni-stuttgart.de
#
# $FreeBSD$
#

DISTNAME=	dmake-v4.1-src-export.all-unknown-all
PKGNAME=	dmake-4.1
CATEGORIES=	devel
MASTER_SITES=	ftp://plg.uwaterloo.ca/pub/dmake/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/dmake
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	bsd43
MAN1=		dmake.1

do-configure:
.for f in limits.h string.h dirent.h
	@${RM} -f ${WRKSRC}/unix/bsd43/$f
.endfor
	 @${CP} ${WRKSRC}/unix/startup.h ${WRKSRC}/unix/startup.h.orig
	@${SED} s:/usr/local:${PREFIX}: ${WRKSRC}/unix/startup.h.orig \
	  > ${WRKSRC}/unix/startup.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dmake ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/dmake.tf ${PREFIX}/man/man1/dmake.1
	${MKDIR} ${PREFIX}/lib/dmake/startup
	${CP} -R ${WRKSRC}/startup/* ${PREFIX}/lib/dmake/startup

.include <bsd.port.mk>
