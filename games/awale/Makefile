# New ports collection makefile for:	awale
# Date created:		15 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	awale
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	African board game

OPTIONS=	GUI "Installs Tcl/Tk GUI" on

MAN1=		${PORTNAME}.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GUI)
PLIST_SUB+=	GUI="@comment "
.else
USE_TK_WRAPPER=	yes
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
MAN1+=		x${PORTNAME}.1
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
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
.for f in README *.bmp *.gif *.ico *.png
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${DATADIR}
.endfor
.if !defined(WITHOUT_X11)
	${INSTALL_SCRIPT} ${WRKSRC}/src/x${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/x${PORTNAME}.1 ${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/src/xawale.tcl ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README THANKS
	cd ${WRKSRC} && ${INSTALL_DATA} ${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
