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

BROKEN=		unfetchable

NO_BUILD=	yes
NO_ARCH=	yes

LIBDIR=		${STAGEDIR}${PREFIX}/include/X11/pixmaps

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${LIBDIR}
	${CP} -R ${WRKSRC}/* ${LIBDIR}/
	-${RM} ${LIBDIR}/README
	-${RM} ${LIBDIR}/readem.shar

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/*.shar ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
