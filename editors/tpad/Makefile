# New ports collection makefile for:	tpad
# Date created:		10 November 2003
# Whom:			Antonio Bonifati <ant@monitor.deis.unical.it>
#
# $FreeBSD$
#

PORTNAME=	tpad
PORTVERSION=	1.2
CATEGORIES=	editors tcl84 tk84
MASTER_SITES=	http://monitor.deis.unical.it/ant/tpad/ \
		http://queen.rett.polimi.it/~ant/tcl/script/

MAINTAINER=	ant@monitor.deis.unical.it
COMMENT=	Windows XP (TM) Notepad clone written in Tcl/Tk

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/MESSAGE

PORTDOCS=	ChangeLog conf.html index.html intro.html keys.html \
		log.html mouse.html todo tpad.html
MAN1=		tpad.1
MLINKS=		tpad.1 tview.1

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bin/tpad ${PREFIX}/bin/tpad

post-install:
	${TEST} -e ${PREFIX}/bin/tview || (cd ${PREFIX}/bin ; ${LN} -s tpad tview)
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKDIR}/man/man1/tpad.1 ${MANPREFIX}/man/man1
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/share/doc/tpad/${docfile} ${DOCSDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKDIR}/etc/tpad.conf \
		${PREFIX}/etc/tpad.conf.sample
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
