# New ports collection makefile for:	ami
# Date created:		05 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ami
PORTVERSION=	1.0.6
CATEGORIES=	korean x11
MASTER_SITES=	http://www.kr.freebsd.org/~hwang/ami/ \
		http://master.debian-kr.org/~cwryu/archive/misc/
DISTFILES=	${DISTNAME}.tar.gz hanja.dic.gz ami.dic
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	cjh@kr.freebsd.org

LIB_DEPENDS=    gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
CONFIGURE_ENV=	GLIB_CONFIG=${LOCALBASE}/bin/glib12-config \
		GTK_CONFIG=${X11BASE}/bin/gtk12-config
CONFIGURE_ARGS+= --with-hangul-keyboard=2

# gnome panel applet support
#.if defined(WITH_GNOME_APPLET)
PKGNAMESUFFIX=	-gnome
RUN_DEPENDS+=	panel:${PORTSDIR}/x11/gnomecore
CONFIGURE_ARGS+= --enable-gnome-applet
.endif

post-build:
	@cd ${WRKSRC}/hanjadic; \
	${MAKE}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hanjadic/hanja-hwp2ami ${PREFIX}/bin

	# patch XLC_LOCALE for ko_KR.EUC(harmless)
	if [ -f ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE ]; then \
		${MV} -f ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE \
			${PREFIX}/lib/X11/locale/ko/XLC_LOCALE.orig; \
	fi
	${INSTALL_DATA} ${FILESDIR}/XLC_LOCALE \
		${PREFIX}/lib/X11/locale/ko/

	${MKDIR} ${PREFIX}/share/doc/ami
	${INSTALL_DATA} ${FILESDIR}/XLC_LOCALE \
		${PREFIX}/share/doc/ami

.for NAME in AUTHORS README NEWS COPYING ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${NAME} \
		${PREFIX}/share/doc/ami
.endfor

	# dic
	${GUNZIP_CMD} -cd ${_DISTDIR}/hanja.dic.gz > \
			${PREFIX}/share/ami/hanja.dic
	${CAT} ${_DISTDIR}/ami.dic >> ${PREFIX}/share/ami/hanja.dic

.include <bsd.port.mk>
