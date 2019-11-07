# Created by: Kelly Yancey <kbyanc@posi.net>
# $FreeBSD$

PORTNAME=	aee
PORTVERSION=	2.2.21
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.users.uswest.net/~hmahon/sources/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Easy editor with both curses and X11 interfaces

BROKEN=		unfetchable

LICENSE=	ART10

USES=		ncurses
PLIST_FILES=	bin/aee bin/rae man/man1/aee.1.gz %%DATADIR%%/help.ae
ALL_TARGET=	main

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	XAE

XAE_DESC=		Build X11 version 'xae'
XAE_USES=		xorg
XAE_USE=		XORG=x11
XAE_PLIST_FILES=	bin/xae bin/rxae
XAE_ALL_TARGET=		xae
XAE_DESKTOP_ENTRIES=	"Xae" "" "" "xae" "" false

post-patch:
	@${REINPLACE_CMD} -e \
		's|cc|${CC}|g ; \
		 s|"-s"|""|g ; \
		 s|/usr/X11R6|${LOCALBASE}|g' \
		 ${WRKSRC}/create.mk.aee \
		 ${WRKSRC}/create.mk.xae
	@${REINPLACE_CMD} -e 's|/usr/local/lib|${DATADIR}|g' \
		${WRKSRC}/aee.1  \
		${WRKSRC}/localize.c

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/aee ${STAGEDIR}${PREFIX}/bin
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} aee rae)
	${INSTALL_MAN} ${WRKSRC}/aee.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/help.ae ${STAGEDIR}${DATADIR}

do-install-XAE-on:
	${INSTALL_PROGRAM} ${WRKSRC}/xae ${STAGEDIR}${PREFIX}/bin
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} xae rxae)

.include <bsd.port.mk>
