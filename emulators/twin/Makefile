# New ports collection makefile for:	Willows
# Date created:		5 June 1999
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	twin
PORTVERSION=	3.1.14
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	emulators devel
MASTER_SITES=	${MASTER_SITE_NETBSD} \
		ftp://ftp.willows.com/pub/twin/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Willows Toolkit for migrating and developing Windows applications

ONLY_FOR_ARCHS=	i386 alpha powerpc

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XLIB=	yes
USE_REINPLACE=	yes
USE_AUTOCONF_VER=	213
GNU_CONFIGURE=	yes
.if ${MACHINE_ARCH} == "alpha"
CONFIGURE_ARGS+=--disable-intp
.endif
USE_GMAKE=	yes

ALL_TARGET=	depend world

PLIST_SUB=	LIBVER="${LIBVER}"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

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

post-configure:
	@${REINPLACE_CMD} 's|bison -y|yacc|' ${WRKSRC}/Make.rules # dirty

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

.include <bsd.port.post.mk>
