# New ports collection makefile for:	ensemblist
# Date created:				06 Sep 2005
# Whom:					Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	ensemblist
PORTVERSION=	040126
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Assemble given shapes from primitives

LIB_DEPENDS=	mikmod.2:${PORTSDIR}/audio/libmikmod \
		png15:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_XORG=	xmu
USE_GL=		glut
MAKE_ARGS=	CC="${CC}" DATADIR="${DATADIR}"

PLIST=		${WRKDIR}/pkg-plist

PLIST_FILES=	bin/ensemblist
PLIST_DIRS=	%%DATADIR%%
MAN6=		ensemblist.6
PORTDOCS=	*

pre-install:
	@${RM} -f ${PLIST}
	@${FIND} ${WRKSRC}/datas -type f | ${SORT} \
		| ${SED} -e 's|^${WRKSRC}/datas|%%DATADIR%%|' >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/datas/* ${DATADIR}

.ifndef (NOPORTDOCS)
	cd ${WRKSRC}/html && \
	${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

	${INSTALL_MAN} ${WRKSRC}/ensemblist.6 ${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
