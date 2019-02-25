# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xabacus
PORTVERSION=	8.0.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.tux.org/~bagleyd/abacus/ \
		http://ftp.tux.org/pub/tux/bagleyd/xabacus/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abacus for X Window System

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2
USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_x_app_defaults=${PREFIX}/lib/X11/app-defaults
CONFIGURE_ARGS=	--without-nas --with-rplay --without-esound
INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="XAbacus" "" "abacus" "${PORTNAME}" "" ""

OPTIONS_DEFINE=		MOTIF
OPTIONS_DEFAULT=	MOTIF

LIB_DEPENDS=	librplay.so:audio/rplay
MOTIF_USES=		motif
MOTIF_CONFIGURE_WITH=	motif

post-patch:
	@${REINPLACE_CMD} -e \
		's|\($$(datadir)\)/games|\1| ; \
		 s|@XWIDGETLDFLAGS@|@LDFLAGS@| ; \
		 s|\([[:blank:]]\)/usr/games|\1$$(DESTDIR)$$(bindir)| ; \
		 /chmod/s|^|#| ; \
		 /chown/s|^|#|' ${WRKSRC}/Makefile.in

post-install:
.for i in 16 22 24 32 48
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	(cd ${WRKSRC}/pixmaps/${i}x${i} && ${INSTALL_DATA} abacus.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps)
.endfor

.include <bsd.port.mk>
