# New ports collection makefile for:	starplot
# Date created:				Mon Aug 20 09:08:07 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	starplot
PORTVERSION=	0.92.3
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://www.princeton.edu/~kmccarty/downloads/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	3-dimensional viewer for star charts

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_XPM=	yes
MAKE_ENV=	DATADIR="${DATADIR}" \
		DOCSDIR="${DOCSDIR}"

MAN1=		starplot.1 starconvert.1

pre-patch:
	@${REINPLACE_CMD} -e 's|DATADIR|${DATADIR}|; s|DOCDIR|${DOCSDIR}|; \
		s|BINARYNAME|${PORTNAME}|; s|CONVERTNAME|starconvert|' \
		${WRKSRC}/doc/man/*
	@${REINPLACE_CMD} -e 's|/usr/local/share/starplot|${DATADIR}|; \
		s|/usr/local/share/doc/starplot|${DOCSDIR}|' \
		${WRKSRC}/gui/starplot.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/starplot ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/starconvert ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/man/starplot-template \
		${PREFIX}/man/man1/starplot.1
	@${INSTALL_MAN} ${WRKSRC}/doc/man/starconvert-template \
		${PREFIX}/man/man1/starconvert.1
	@${MKDIR} ${DATADIR}/examples
	@${INSTALL_DATA} ${WRKSRC}/examples/*.stars ${DATADIR}/examples
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/examples ${DOCSDIR}/html/images
	@${INSTALL_DATA} ${WRKSRC}/examples/example.spec ${DOCSDIR}/examples
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}/html
	@${INSTALL_DATA} ${WRKSRC}/doc/html/images/* ${DOCSDIR}/html/images
.endif

.include <bsd.port.mk>
