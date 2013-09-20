# Created by: Kelly Yancey <kbyanc@posi.net>
# $FreeBSD$

PORTNAME=	aee
PORTVERSION=	2.2.15b
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.users.uswest.net/~hmahon/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy editor with both curses and X11 interfaces

LICENSE=	ART10

OPTIONS_DEFINE=	XAE
XAE_DESC=	Build X11 version 'xae'

MAKE_JOBS_UNSAFE=	yes

MAN1=		aee.1
PLIST_FILES=	bin/aee bin/rae %%DATADIR%%/help.ae
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
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
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} aee ${PREFIX}/bin)
	(cd ${PREFIX}/bin && ${LN} aee rae)
	(cd ${WRKSRC} && ${INSTALL_MAN} aee.1 ${MANPREFIX}/man/man1)
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} help.ae ${DATADIR})
.if ${PORT_OPTIONS:MXAE}
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} xae ${PREFIX}/bin)
	(cd ${PREFIX}/bin && ${LN} xae rxae)
.endif

.include <bsd.port.mk>
