# New ports collection makefile for:	marathon-evil
# Date created:		01 April 2001
# Whom:			Bruce A. Mah <bmah@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	marathon-evil
PORTVERSION=	3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://archives2.bungie.org/a1sdl/ \
		ftp://ftp2.bungie.org/archives/a1sdl/
DISTNAME=	MarathonEvil-3

MAINTAINER=	bmah@freebsd.org
COMMENT=	Marathon-Evil scenario for use with AlephOne

RUN_DEPENDS=	alephone:${PORTSDIR}/games/alephone

USE_X_PREFIX=	yes
NO_CDROM=	Bungie/Microsoft do not allow charging for Marathon data files.

WRKSRC=		${WRKDIR}/MarathonEvil

# For some inexplicable reason, there's a tarball inside the tarball.
# We'll deal with the inner tarball as the build.
do-build:
	cd ${WRKSRC}; \
	${GUNZIP_CMD} -c ${WRKSRC}/MarathonEvilData.tar.gz | ${TAR} -xf -

do-install:
	${MKDIR} ${PREFIX}/share/AlephOne
	${INSTALL_DATA} ${WRKSRC}/Cursed.Data ${PREFIX}/share/AlephOne/Cursed.Data
	${INSTALL_DATA} ${WRKSRC}/Cursed.Images ${PREFIX}/share/AlephOne/Cursed.Images
	${INSTALL_DATA} ${WRKSRC}/Cursed.Map ${PREFIX}/share/AlephOne/Cursed.Map
	${INSTALL_DATA} ${WRKSRC}/Cursed.Music ${PREFIX}/share/AlephOne/Cursed.Music
	${INSTALL_DATA} ${WRKSRC}/Cursed.Net.Map ${PREFIX}/share/AlephOne/Cursed.Net.Map
	${INSTALL_DATA} ${WRKSRC}/Cursed.Net.Physics ${PREFIX}/share/AlephOne/Cursed.Net.Physics
	${INSTALL_DATA} ${WRKSRC}/Cursed.Physics ${PREFIX}/share/AlephOne/Cursed.Physics
	${INSTALL_DATA} ${WRKSRC}/Cursed.Shapes ${PREFIX}/share/AlephOne/Cursed.Shapes
	${INSTALL_DATA} ${WRKSRC}/Cursed.Sounds ${PREFIX}/share/AlephOne/Cursed.Sounds
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/AlephOne/README.Evil

post-install:
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
