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
OPTIONS_SUB=	yes
GUI_DESC=	Installs Tcl/Tk GUI

GUI_RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/bin\/bash/d' ${WRKSRC}/src/xawale.tcl
	@${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/src/x${PORTNAME}
	@${ECHO_CMD} "${DATADIR}/xawale.tcl" >> ${WRKSRC}/src/x${PORTNAME}
	@${REINPLACE_CMD} -e 's|wish|wish8.4|' ${WRKSRC}/src/xawale.tcl

do-build:
	(cd ${WRKSRC}/src && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in README *.bmp *.gif *.ico *.png
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${STAGEDIR}${DATADIR}
.endfor
.if ${PORT_OPTIONS:MGUI}
	${INSTALL_SCRIPT} ${WRKSRC}/src/x${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/x${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
	${INSTALL_SCRIPT} ${WRKSRC}/src/xawale.tcl ${STAGEDIR}${DATADIR}
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README THANKS
	cd ${WRKSRC} && ${INSTALL_DATA} ${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
