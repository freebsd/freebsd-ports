# New ports collection makefile for:	ncdialog
# Date created:		2003-01-11
# Whom:			AlanE <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cdialog
PORTVERSION=	1.0.20060221
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/dialog/
DISTNAME=	${PORTNAME:S|^c||}-${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sylvioc@gmail.com
COMMENT=	An enhanced version of 'dialog' to work with ncurses

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKEFILE=	makefile

MAN1=		cdialog.1
MAN3=		cdialog.3
MANCOMPRESSED=	no

INSTALL_TARGET=	install-strip install-lib

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}

.include <bsd.port.mk>
