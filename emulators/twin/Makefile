# New ports collection makefile for:	Willows
# Date created:		5 June 1999
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	twin
PORTVERSION=	3.1.14
PORTEPOCH=	1
CATEGORIES=	emulators devel
MASTER_SITES=	ftp://ftp.willows.com/pub/twin/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Willows Toolkit for migrating and developing Windows applications

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debugger
ALL_TARGET=	depend world
PLIST_SUB=	LIBVER="${LIBVER}"
INSTALLS_SHLIB=	yes

FMT?=	/usr/bin/fmt

LIBRARIES=	libadvapi32.so libcomctl32.so libcomm.so \
	libcommdlg.so libddeml.so libkeyboard.so \
	liblzexpand.so libmmsystem.so libmsvcrt.so \
	libolecli.so libolesvr.so libpe32.so \
	libshell.so libsound.so libsystem.so \
	libtoolhelp.so libtwin32.so libversion.so \
	libw32sys.so libwin87em.so libwinsock.so \
	libwinspool.so
LIBVER=	0

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/documentation/* ${DOCSDIR}
.endif
# version these libraries to make ldconfig happy
.for lib in ${LIBRARIES}
	@${LN} -sf ${lib} ${PREFIX}/lib/${lib}.${LIBVER}
.endfor
	@${FMT} ${PKGMESSAGE}

.include <bsd.port.mk>
