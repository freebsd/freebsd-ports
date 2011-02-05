# New ports collection makefile for:	wargus
# Date created:			1 Jul 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	wargus
PORTVERSION=	2.2.5.5
CATEGORIES=	games
MASTER_SITES=	http://launchpadlibrarian.net/59493162/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Warcraft 2 mod that allows you to play Warcraft 2 with Stratagus

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png
RUN_DEPENDS=	stratagus:${PORTSDIR}/games/stratagus

LICENSE=	GPLv2
NOT_FOR_ARCHS=	sparc64
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehack gnometarget
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SUB_FILES=	${PORTNAME} pkg-message

MAKE_ARGS+=	CFLAGS+=-I${LOCALBASE}/include LDFLAGS+=-L${LOCALBASE}/lib

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	cd ${WRKSRC} && \
	    ${FIND} campaigns contrib maps scripts -type d \
	    -exec ${MKDIR} "${DATADIR}/{}" \; && \
	    ${FIND} campaigns contrib maps scripts -type f \
	    -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
	${INSTALL_PROGRAM} ${WRKSRC}/wartool ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/build.sh ${DATADIR}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
