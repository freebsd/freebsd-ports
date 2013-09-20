# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	awale
PORTVERSION=	1.5
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	African board game

OPTIONS_DEFINE=	GUI DOCS
OPTIONS_DEFAULT=	GUI
GUI_DESC=	Installs Tcl/Tk GUI

MAN6=		${PORTNAME}.6

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
USE_TK_WRAPPER=	yes
MAN6+=		x${PORTNAME}.6
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/bin\/bash/d' ${WRKSRC}/src/xawale.tcl
	@${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/src/x${PORTNAME}
	@${ECHO_CMD} "${DATADIR}/xawale.tcl" >> ${WRKSRC}/src/x${PORTNAME}

do-build:
	(cd ${WRKSRC}/src && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.6 ${MAN6PREFIX}/man/man6
	@${MKDIR} ${DATADIR}
.for f in README *.bmp *.gif *.ico *.png
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${DATADIR}
.endfor
.if ${PORT_OPTIONS:MGUI}
	${INSTALL_SCRIPT} ${WRKSRC}/src/x${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/x${PORTNAME}.6 ${MAN6PREFIX}/man/man6
	${INSTALL_SCRIPT} ${WRKSRC}/src/xawale.tcl ${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README THANKS
	cd ${WRKSRC} && ${INSTALL_DATA} ${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
