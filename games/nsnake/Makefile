PORTNAME=	nsnake
DISTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://releases.malikania.fr/nsnake/${PORTVERSION}/

MAINTAINER=	markand@malikania.fr
COMMENT=	Snake game written in C and ncurses
WWW=		https://projects.malikania.fr/nsnake/

LICENSE=	ISCL

USES=		ncurses tar:xz

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

MAKE_ENV=	CC="$CC" \
		CFLAGS+="$CFLAGS" \
		LDFLAGS+="$LDFLAGS"

post-patch:
	@${REINPLACE_CMD} -e 's|VARDIR=.*|VARDIR=/var|' \
		${WRKSRC}/config.mk
do-install:
	(cd ${WRKSRC} \
		&& ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin \
		&& ${INSTALL_MAN} ${PORTNAME}.6 ${STAGEDIR}${PREFIX}/share/man/man6)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CHANGES.md ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}/var/db/nsnake

.include <bsd.port.mk>
