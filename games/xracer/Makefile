# New ports collection makefile for:	xracer
# Date created:				Nov 6th 1999
# Whom:					troll
#
# $FreeBSD$
#

PORTNAME=	xracer
PORTVERSION=	0.94
CATEGORIES=	games
MASTER_SITES=	http://xracer.annexia.org/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xracer-data.tar.gz

MAINTAINER=	troll@digitalspark.net

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_XLIB=	yes
USE_MESA=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-esd

post-patch:
	@${TOUCH} ${WRKSRC}/stamp-h.in

post-install:
	@${ECHO} "===>   Installing Tracks and Sound"
	@${MKDIR} ${PREFIX}/share/xracer
	${TAR} -C ${WRKDIR}/xracer-data -cf - . | \
		${TAR} -C ${PREFIX}/share/xracer --unlink -xf -
	@${CHMOD} -R 744 ${PREFIX}/share/xracer
	@${CHMOD} -R a+X ${PREFIX}/share/xracer
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Documentation"
	@${MKDIR} ${PREFIX}/share/doc/xracer
.for file in AUTHORS ChangeLog NEWS README README.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xracer
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
