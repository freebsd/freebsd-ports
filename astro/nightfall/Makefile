# New ports collection makefile for:      nightfall
# Date created:         21 February 2002
# Whom:                 Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	nightfall
PORTVERSION=	1.1
CATEGORIES=	astro
MASTER_SITES=	http://www.lsw.uni-heidelberg.de/~rwichman/ \
		http://unixpages.org/distfiles/

MAINTAINER=	chris@unixpages.org

.if !defined(WITHOUT_GTK)
USE_GNOMENG=	yes
USE_GNOME=	gtk12
.endif
.if !defined(WITHOUT_GNUPLOT)
BUILD_DEPENDS+= gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS+=   gnuplot:${PORTSDIR}/math/gnuplot
.endif
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= \
		--with-doc-prefix=${DOCSDIR} \
		--with-data-prefix=${PREFIX}/share/nightfall

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nightfall ${PREFIX}/bin/nightfall
	${MKDIR} ${PREFIX}/share/nightfall/data
	${INSTALL_DATA} ${WRKSRC}/data/* ${PREFIX}/share/nightfall/data
	${MKDIR} ${DOCSDIR}/C
	${MKDIR} ${DOCSDIR}/de
	${INSTALL_DATA} ${WRKSRC}/doc/C/* ${DOCSDIR}/C
	${INSTALL_DATA} ${WRKSRC}/doc/de/* ${DOCSDIR}/de
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

.include <bsd.port.mk>
