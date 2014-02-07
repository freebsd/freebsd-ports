# Created by: refugee
# $FreeBSD$

PORTNAME=	typespeed
PORTVERSION=	0.6.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Test your typing speed and get your fingers\' CPS

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

USES=		ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-highscoredir="${SCOREDIR}"

CFLAGS+=	-I${LOCALBASE}/include -DWITH_HIGHSCOREDIR=\"${SCOREDIR}\"  \
		-DHIGHDIR=\"${SCOREDIR}\" -DHIGHSCOREDIR=\"${SCOREDIR}\"

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	SCOREDIR="${SCOREDIR}" SCOREFILE="${SCOREFILE}"

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

SCOREPREFIX?=	/var/games
SCOREDIR=	${SCOREPREFIX}/typespeed
SCOREFILE=	typespeed.score

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^\(CC =\).*|\1 @CC@|'
	@${REINPLACE_CMD} -e \
		's|\(/etc\)|${PREFIX}\1|' ${WRKSRC}/src/pathnames.h

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} convert \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-hs-conv)
	(cd ${WRKSRC}/man && ${INSTALL_MAN} ${PORTNAME}.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6)
	(cd ${WRKSRC}/etc && ${INSTALL_DATA} typespeedrc \
		${STAGEDIR}${PREFIX}/etc/typespeedrc.dist)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/src && ${INSTALL_DATA} ${SCOREFILE} \
		${STAGEDIR}${DATADIR}/${SCOREFILE}.default)
	@${MKDIR} ${STAGEDIR}${DATADIR}/words
	(cd ${WRKSRC}/words && ${INSTALL_DATA} words.* \
		${STAGEDIR}${DATADIR}/words)
.if ${PORT_OPTIONS:MNLS}
.for i in de_DE fr_FR it
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES
	(cd ${WRKSRC}/po && ${INSTALL_DATA} ${i}.gmo \
		${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/typespeed.mo)
.endfor
.endif

.include <bsd.port.mk>
