# New ports collection makefile for:	hobbes-icons-xpm3
# Date created:		19 October 1996
# Whom:			pgs
#
# $FreeBSD$
#

PORTNAME=	hobbes-icons-xpm3
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
NO_BUILD=	yes

# Where it will be installed (change pkg/PLIST if you change this)
LIBDIR=		${PREFIX}/include/X11/pixmaps

do-install:
	@${MKDIR} ${LIBDIR}
	${CP} -R ${WRKSRC}/* ${LIBDIR}
	${CHOWN} -R ${BINOWN}:${BINGRP} ${LIBDIR}
	-${RM} ${LIBDIR}/README
	-${RM} ${LIBDIR}/readem.shar

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/*.shar ${DOCSDIR}
.endif

.include <bsd.port.mk>
