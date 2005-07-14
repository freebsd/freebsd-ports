# New ports collection makefile for:	gtklife
# Date created:			07 Aug 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	gtklife
PORTVERSION=	4.2
CATEGORIES=	games
MASTER_SITES=	http://ironphoenix.org/tril/gtklife/

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A GTK+ implementation of Conway's Game of Life

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}" DOCDIR="${DOCSDIR}"

PLIST=		${WRKDIR}/pkg-plist
PLIST_FILES=	bin/gtklife
PLIST_DIRS=	%%DATADIR%%
PORTDOCS=	*

DATA_SUBDIRS=	graphics patterns

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|' ${WRKSRC}/Makefile

pre-install:
	@cd ${WRKSRC} && >${PLIST} && \
	${FIND} ${DATA_SUBDIRS} ! -type d | ${SORT} \
		| ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} ${DATA_SUBDIRS} -type d ! -empty | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtklife ${PREFIX}/bin
	cd ${WRKSRC} && \
	${FIND} ${DATA_SUBDIRS} -type d ! -empty -exec ${MKDIR} "${DATADIR}/{}" \; && \
	${FIND} ${DATA_SUBDIRS} ! -type d -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
