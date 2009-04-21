# New ports collection makefile for:	ncmpc
# Date created:		Apr 14 2004
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	ncmpc
PORTVERSION=	0.14
CATEGORIES=	audio
MASTER_SITES=	SF/musicpd

MAINTAINER=	hrkfdn@gmail.com
COMMENT=	Ncurses client for the musicpd

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	NLS "Native language support" on

.include <bsd.port.pre.mk>

USE_ICONV=	yes
PLIST_FILES=	bin/ncmpc \
	%%EXAMPLESDIR%%/config \
	%%EXAMPLESDIR%%/keys \
	%%EXAMPLESDIR%%/ncmpc.lirc
PLIST_DIRS=%%EXAMPLESDIR%%

.ifdef(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.else
USE_GETTEXT=	yes
LANGUAGES=cs da de es fr gl hu ko nb nl ru sk sv uk zh_CN
.for language in ${LANGUAGES}
PLIST_FILES+=share/locale/${language}/LC_MESSAGES/ncmpc.mo
.endfor

.endif

MAN1=		ncmpc.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpc ${PREFIX}/bin/
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/config.sample ${EXAMPLESDIR}/config
	${INSTALL_DATA} ${WRKSRC}/doc/keys.sample ${EXAMPLESDIR}/keys
	${INSTALL_DATA} ${WRKSRC}/doc/ncmpc.lirc ${EXAMPLESDIR}/
	${INSTALL_MAN} ${WRKSRC}/doc/ncmpc.1 ${MAN1PREFIX}/man/man1/
.if !defined(WITHOUT_NLS)
.for language in ${LANGUAGES}
	${MKDIR} ${LOCALBASE}/share/locale/${language}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${language}.gmo ${PREFIX}/share/locale/${language}/LC_MESSAGES/ncmpc.mo
.endfor
.endif

.include <bsd.port.post.mk>
