# New ports collection makefile for:	ncmpc
# Date created:		Apr 14 2004
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	ncmpc
PORTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://hem.bredband.net/kaw/ncmpc/files/ \
		http://mercury.chem.pitt.edu/~shank/

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Ncurses client for the musicpd

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	NLS "Native language support" on \
		CLOCK_SCREEN "Enable clock screen" on

.include <bsd.port.pre.mk>

USE_ICONV=	yes
PLIST_FILES=	bin/ncmpc \
	%%EXAMPLESDIR%%/config \
	%%EXAMPLESDIR%%/keys \
	=%%EXAMPLESDIR%%/ncmpc.lirc
PLIST_DIRS=%%EXAMPLESDIR%%

.ifdef(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.else
USE_GETTEXT=	yes
LANGUAGES=de sv es ru fr
.for language in ${LANGUAGES}
PLIST_FILES+=share/locale/${language}/LC_MESSAGES/ncmpc.mo
.endfor

.endif

.if !defined(WITHOUT_CLOCK_SCREEN)
CONFIGURE_ARGS+=--enable-clock-screen
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
