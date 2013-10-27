# Created by: pgs
# $FreeBSD$

PORTNAME=	hobbes-icons-xpm3
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTNAME=	${PORTNAME}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Collection of over 3000 icons in XPM3 format

NO_BUILD=	yes
NEED_ROOT=	yes

LIBDIR=		${STAGEDIR}${PREFIX}/include/X11/pixmaps

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${LIBDIR}
	${CP} -R ${WRKSRC}/* ${LIBDIR}/
	${CHOWN} -R ${BINOWN}:${BINGRP} ${LIBDIR}
	-${RM} ${LIBDIR}/README
	-${RM} ${LIBDIR}/readem.shar

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/*.shar ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
