# New ports collection makefile for:	ascd
# Version required:		0.13.2
# Date created:			29 November 1998
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	ascd-0.13.2-src
PKGNAME=	ascd-0.13.2
CATEGORIES=	audio afterstep windowmaker
MASTER_SITES=	http://worldserver.oleane.com/rsn/Archives/
DISTFILES=	${DISTNAME}.tgz ${DATAFILES}

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		workman.1:${PORTSDIR}/audio/libworkman

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_IMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	default
DATAFILES=	ascd-0.13pr6-themes.tgz
THEMESDIR=	ascd-0.13pr6-themes

MAN1=		ascd.1

post-patch:
	@${LN} -fs ${WRKSRC}/misc/default ${WRKSRC}/default

post-install:
	@${CP} ${FILESDIR}/install ${WRKDIR}/${THEMESDIR}
	@(cd ${WRKDIR}/${THEMESDIR} && ./install)

.include <bsd.port.mk>
