# New ports collection makefile for:  roadmap
# Date created:        4 November 2002
# Whom:                Nick Esborn <nick@netdot.net>
#
# $FreeBSD$
#

PORTNAME=	roadmap
PORTVERSION=	0.13
CATEGORIES=	astro
MASTER_SITES=	http://www.geocities.com/pascal_f_martin/roadmap/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	nick@netdot.net
COMMENT=	RoadMap is a displays US maps provided by the US Census Bureau

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src/gtk
INSTALL_WRKSRC=	${WRKSRC}/src

USE_GNOMENG=	yes
USE_GNOME=	gtk12

BINS=		buildmap buildus dumpmap
GUI_BINS=	gtkroadmap gtkroadgps
SCRIPTS=	rdmdownload rdmgetall rdmgenmaps rdmcompare
DATA=		sprites preferences schema
DOCS=		AUTHORS BUGS COPYING README TODO

do-install:
.for _GUI_BIN in ${GUI_BINS}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/gtk/${_GUI_BIN} ${X11BASE}/bin/${_GUI_BIN}
.endfor
.for _BIN in ${BINS}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${_BIN} ${LOCALBASE}/bin/${_BIN}
.endfor
.for _SCRIPT in ${SCRIPTS}
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/${_SCRIPT} ${LOCALBASE}/bin/${_BIN}
.endfor
	${MKDIR} ${DATADIR}
.for _DATA in ${DATA}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${_DATA} ${DATADIR}/${_DATA}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for _DOC in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${_DOC} ${DOCSDIR}/${_DOC}
.endfor
.endif

post-install:
	@${SED} -e "s|%%DOCSDIR%%|${DOCSDIR}|" ${PKGMESSAGE}

.include <bsd.port.mk>
