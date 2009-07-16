# New ports collection makefile for:	ncdialog
# Date created:		2003-01-11
# Whom:			AlanE <alane@freebsd.org>
#
# $Carpetsmoker: ports/cdialog/Makefile,v 1.4 2007/04/22 11:30:53 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	cdialog
PORTVERSION=	1.1.20080819
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/dialog/ \
		http://www.xs4all.nl/~tournoij/distfiles/ \
		http://www.rwxrwxrwx.net/distfiles/
DISTNAME=	${PORTNAME:S|^c||}-${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	An enhanced version of 'dialog' to work with ncurses

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME} --with-libtool
MAKEFILE=	makefile

MAN1=		cdialog.1
MAN3=		cdialog.3
MANCOMPRESSED=	no

INSTALL_TARGET=	install-strip install-man install-lib

post-patch:
	@${FIND} ${WRKSRC}/samples/ -type f -exec ${REINPLACE_CMD} -i "" "s|dialog|cdialog|g" {} \;

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700032 || (${OSVERSION} < 700000 && ${OSVERSION} > 602106)
CONFIGURE_ARGS+=	--with-ncursesw --enable-widec
.else
CONFIGURE_ARGS+=	--with-ncurses
.endif

.include <bsd.port.post.mk>
