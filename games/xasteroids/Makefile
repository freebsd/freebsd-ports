# New ports collection makefile for:    xasteroids
# Date created:		3 Jan 1995
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	xasteroids
PORTVERSION=	5.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.isst.fhg.de/pub/windows/X/notinstalled_pack/ \
		ftp://ftp.opengroup.org/pub/ftp.x.org/R5contrib/ \
		ftp://ftp.x.org/pub/R5contrib/
DISTFILES=	xasteroids.sh.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 based asteroids style arcade game

USE_IMAKE=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	( cd ${WRKDIR}; zcat | sh -s )
EXTRACT_BEFORE_ARGS=	<
EXTRACT_AFTER_ARGS=	# empty
MAN6=		xasteroids.6
PLIST_FILES=	bin/xasteroids

post-extract:
	${CP} ${FILESDIR}/Imakefile ${WRKSRC}
	${CP} ${WRKSRC}/xast.man ${WRKSRC}/xasteroids.man

.include <bsd.port.mk>
