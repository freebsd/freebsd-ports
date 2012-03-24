# New ports collection makefile for:	awale
# Date created:		15 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	awale
PORTVERSION=	1.5
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	African board game

OPTIONS=	GUI "Installs Tcl/Tk GUI" on

MAN6=		${PORTNAME}.6

.include <bsd.port.options.mk>

.if defined(WITHOUT_GUI)
PLIST_SUB+=	GUI="@comment "
.else
USE_TK_WRAPPER=	yes
MAN6+=		x${PORTNAME}.6
PLIST_SUB+=	GUI=""
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
.if !defined(WITHOUT_GUI)
	${INSTALL_SCRIPT} ${WRKSRC}/src/x${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/x${PORTNAME}.6 ${MAN6PREFIX}/man/man6
	${INSTALL_SCRIPT} ${WRKSRC}/src/xawale.tcl ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README THANKS
	cd ${WRKSRC} && ${INSTALL_DATA} ${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
