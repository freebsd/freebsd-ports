# Created by: Antonio Bonifati <ant@monitor.deis.unical.it>
# $FreeBSD$

PORTNAME=	tpad
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	editors tcl tk
MASTER_SITES=	SF/tclpad/tclpad/${PORTVERSION} \
		http://monitor.deis.unical.it/ant/tpad/ \
		http://queen.rett.polimi.it/~ant/tcl/script/ \
		http://sarovar.org/download.php/382/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Windows XP (TM) enhanced Notepad clone written in Tcl/Tk

RUN_DEPENDS=	wish8.4:x11-toolkits/tk84

NO_BUILD=	yes

PORTDOCS=	ChangeLog bug.html conf.html embed.html index.html intro.html \
		keys.html log.html mouse.html tidy.html tidy.png todo tpad.html
PLIST_SUB=	LIBDIR=lib/tpad${PORTVERSION}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bin/tpad ${STAGEDIR}${PREFIX}/bin/tpad
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/tpad${PORTVERSION}/msgs
	(cd ${WRKDIR}/lib/tpad${PORTVERSION} && ${INSTALL_DATA} *.tcl \
		${STAGEDIR}${PREFIX}/lib/tpad${PORTVERSION})
	(cd ${WRKDIR}/lib/tpad${PORTVERSION}/msgs && ${INSTALL_DATA} *.msg \
		${STAGEDIR}${PREFIX}/lib/tpad${PORTVERSION}/msgs)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR}/share/tpad && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s tpad tview)
	${INSTALL_MAN} ${WRKDIR}/man/man1/tpad.1 ${STAGEDIR}${MANPREFIX}/man/man1
	(cd ${STAGEDIR}${MANPREFIX}/man/man1 && ${LN} -s tpad.1.gz tview.1.gz)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/share/doc/tpad && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKDIR}/etc/tpad.conf \
		${STAGEDIR}${PREFIX}/etc/tpad.conf.sample

.include <bsd.port.mk>
