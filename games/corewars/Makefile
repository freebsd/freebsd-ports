# New ports collection makefile for:	corewars
# Version required:		0.9.0
# Date created:			29 February 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	corewars-0.9.0
CATEGORIES=	games
MASTER_SITES=	http://download.sourceforge.net/corewars/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

post-install:
	@strip ${PREFIX}/bin/corewars
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing README in ${PREFIX}/share/doc/corewars."
	@${ECHO} "===>   Please read it before playing."
	@${MKDIR} ${PREFIX}/share/doc/corewars && ${CHMOD} a+rx ${PREFIX}/share/doc/corewars
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/corewars
.endif

.include <bsd.port.mk>
