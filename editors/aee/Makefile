# Created by: Kelly Yancey <kbyanc@posi.net>
# $FreeBSD$

PORTNAME=	aee
PORTVERSION=	2.2.21
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.users.uswest.net/~hmahon/sources/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Easy editor with both curses and X11 interfaces

LICENSE=	ART10

USES=		ncurses

OPTIONS_DEFINE=	XAE
XAE_DESC=	Build X11 version 'xae'

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/aee bin/rae man/man1/aee.1.gz %%DATADIR%%/help.ae

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXAE}
USE_XORG=	x11
ALL_TARGET=	both
PLIST_FILES+=	bin/xae bin/rxae
DESKTOP_ENTRIES="Xae" "" "" "xae" "" false
.else
ALL_TARGET=	main
.endif

post-patch:
.for i in create.mk.aee create.mk.xae
	@${REINPLACE_CMD} -e \
		's|cc|${CC}|g ; \
		 s|"-s"|""|g ; \
		 s|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/${i}
.endfor
.for i in aee.1 localize.c
	@${REINPLACE_CMD} -e \
		's|/usr/local/lib|${DATADIR}|g' ${WRKSRC}/${i}
.endfor

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} aee ${STAGEDIR}${PREFIX}/bin)
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} aee rae)
	(cd ${WRKSRC} && ${INSTALL_MAN} aee.1 ${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} help.ae ${STAGEDIR}${DATADIR})
.if ${PORT_OPTIONS:MXAE}
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} xae ${STAGEDIR}${PREFIX}/bin)
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} xae rxae)
.endif

.include <bsd.port.mk>
