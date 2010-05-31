# New ports collection makefile for: typespeed
# Date created:        06 September 2003
# Whom:                refugee
#
# $FreeBSD$
#

PORTNAME=	typespeed
PORTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF \
		http://tobias.eyedacor.org/typespeed/


MAINTAINER=	ports@FreeBSD.org
COMMENT=	Test your typing speed, and get your fingers\' CPS

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-highscoredir="/var/games/typespeed"

SCOREPREFIX?=	/var/games
SCOREDIR=	${SCOREPREFIX}/typespeed
SCOREFILE=	typespeed.score

CFLAGS+=	-I${LOCALBASE}/include -DWITH_HIGHSCOREDIR=\"${SCOREDIR}\"  \
		-DHIGHDIR=\"${SCOREDIR}\" -DHIGHSCOREDIR=\"${SCOREDIR}\"

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	SCOREDIR="${SCOREDIR}" SCOREFILE="${SCOREFILE}" WRKSRC="${WRKSRC}"
MAN1=		typespeed.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\(/etc\)|${PREFIX}\1|' \
		${WRKSRC}/src/pathnames.h

do-install:
	${INSTALL_PROGRAM} -g games -m 2555 ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/convert ${PREFIX}/bin/${PORTNAME}-hs-conv
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.6 ${MANPREFIX}/man/man1/${MAN1}
	${INSTALL_DATA} ${WRKSRC}/etc/typespeedrc ${PREFIX}/etc/typespeedrc.dist
.if !exists(${PREFIX}/etc/typespeedrc)
	${INSTALL_DATA} ${WRKSRC}/etc/typespeedrc ${PREFIX}/etc
.endif
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/words
	${FIND} ${WRKSRC}/words/ -name "words.*" -type f \
		-exec ${INSTALL_DATA} {} ${DATADIR}/words \;
.if !defined(WITHOUT_NLS)
.for i in de_DE fr_FR it
	${MKDIR} ${PREFIX}/share/locale/${i}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${i}.gmo \
		${PREFIX}/share/locale/${i}/LC_MESSAGES/typespeed.mo
.endfor
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
