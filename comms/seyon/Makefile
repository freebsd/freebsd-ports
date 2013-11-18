# Created by: Michael Elbel (me)
# $FreeBSD$

PORTNAME=	seyon
PORTVERSION=	2.14b
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	ftp://sipb.mit.edu/pub/seyon/
DISTNAME=	Seyon-${PORTVERSION}
EXTRACT_SUFX=	-tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Communications package for the X Window system

WRKSRC=		${WRKDIR}/seyon
USES=		imake
USE_XORG=	x11 xext xpm xmu xaw xt sm ice
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/seyon lib/X11/app-defaults/Seyon \
		lib/X11/app-defaults/Seyon-color lib/X11/seyon.help \
		man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
