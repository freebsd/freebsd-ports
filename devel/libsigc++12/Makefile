# New ports collection makefile for:   libsigc++
# Date created:        27 January 2000
# Whom:                Joe Lu <JoeLu@JoeLu.m8.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	libsigc++
PORTVERSION=	1.0.4
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	libsigc \
			sources/libsigc++/1.0
			
#DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libsigc++
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libsigc++
	${INSTALL_DATA} ${WRKSRC}/FEATURES ${PREFIX}/share/doc/libsigc++
	${INSTALL_DATA} ${WRKSRC}/doc/API ${PREFIX}/share/doc/libsigc++
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${PREFIX}/share/doc/libsigc++
	${INSTALL_DATA} ${WRKSRC}/doc/UML ${PREFIX}/share/doc/libsigc++
	${INSTALL_DATA} ${WRKSRC}/doc/conventions ${PREFIX}/share/doc/libsigc++
	${INSTALL_DATA} ${WRKSRC}/doc/diagrams ${PREFIX}/share/doc/libsigc++
	${INSTALL_DATA} ${WRKSRC}/doc/marshal ${PREFIX}/share/doc/libsigc++
	${INSTALL_DATA} ${WRKSRC}/doc/powerusers ${PREFIX}/share/doc/libsigc++
	${INSTALL_DATA} ${WRKSRC}/doc/requirements ${PREFIX}/share/doc/libsigc++
	${INSTALL_DATA} ${WRKSRC}/doc/riscos ${PREFIX}/share/doc/libsigc++/
	${INSTALL_DATA} ${WRKSRC}/doc/signals ${PREFIX}/share/doc/libsigc++
	${INSTALL_DATA} ${WRKSRC}/doc/win32 ${PREFIX}/share/doc/libsigc++
.endif

.include <bsd.port.mk>
