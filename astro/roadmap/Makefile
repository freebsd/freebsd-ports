# New ports collection makefile for:  roadmap
# Date created:        4 November 2002
# Whom:                Nick Esborn <nick@netdot.net>
#
# $FreeBSD$
#

PORTNAME=	roadmap
PORTVERSION=	1.0.r6
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://roadmap.saignon.net/roadmap/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_1_0rc6_src

MAINTAINER=	nick@netdot.net
COMMENT=	Vector-based GPS moving map

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

USE_GNOME=	gtk12

USE_GMAKE=yes

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
