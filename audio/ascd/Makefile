# New ports collection makefile for:	ascd
# Date created:			29 November 1998
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ascd
PORTVERSION=	0.13.2
CATEGORIES=	audio afterstep windowmaker
MASTER_SITES=	http://worldserver.oleane.com/rsn/Archives/
DISTFILES=	${DISTNAME}-src.tgz ${DATAFILES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockable cd player for AfterStep or WindowMaker

LIB_DEPENDS=	workman.1:${PORTSDIR}/audio/libworkman

USE_IMAKE=	yes
USE_XPM=	yes

DATAFILES=	ascd-0.13pr6-themes.tgz
THEMESDIR=	ascd-0.13pr6-themes

MAN1=		ascd.1

post-patch:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
		${WRKSRC}/misc/config.h.default > ${WRKSRC}/config.h
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
		${WRKSRC}/misc/dirs.h.default > ${WRKSRC}/dirs.h
	@${CAT} ${WRKSRC}/version.h >> ${WRKSRC}/config.h

post-install:
	@${CP} ${FILESDIR}/install ${WRKDIR}/${THEMESDIR}
	@(cd ${WRKDIR}/${THEMESDIR} && ./install)

.include <bsd.port.mk>
