PORTNAME=	ninja
PORTVERSION=	1.5.8.1
CATEGORIES=	irc
PKGNAMEPREFIX=	irc-
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another ircII based irc client

DEPRECATED=	Abandonware, last release around 2002 and upstream is gone. Consider irc/ircII or irc/irssi
EXPIRATION_DATE=2024-03-31

USES=		ncurses

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	IRCLIB="${DATADIR}"
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ninja ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ninjawserv ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/translation
	${INSTALL_DATA} ${WRKSRC}/translation/* ${STAGEDIR}${DATADIR}/translation

.include <bsd.port.mk>
