# ex:ts=8
# -*-mode: makefile-*-
#
# New ports collection makefile for:	ncdialog
# Date created:		2003-01-11
# Whom:			AlanE <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cdialog
PORTVERSION=	1.0.20040729
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/dialog/
DISTNAME=	${PORTNAME:S|^c||}-${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An enhanced version of 'dialog' to work with ncurses

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKEFILE=	makefile

MAN1=		cdialog.1
MAN3=		cdialog.3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dialog ${PREFIX}/bin/cdialog
	@${MKDIR} ${PREFIX}/include/cdialog
	${INSTALL_DATA} ${WRKSRC}/dialog.h ${PREFIX}/include/cdialog/dialog.h
	${INSTALL_DATA} ${WRKSRC}/dlg_colors.h ${PREFIX}/include/cdialog/dlg_colors.h
	${INSTALL_DATA} ${WRKSRC}/dlg_config.h ${PREFIX}/include/cdialog/dlg_config.h
	${INSTALL_DATA} ${WRKSRC}/libdialog.a ${PREFIX}/lib/libcdialog.a
	${INSTALL_MAN} ${WRKSRC}/dialog.1 ${MAN1PREFIX}/man/man1/cdialog.1
	${INSTALL_MAN} ${WRKSRC}/dialog.3 ${MAN3PREFIX}/man/man3/cdialog.3
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
