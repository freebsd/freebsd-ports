# $FreeBSD$

PORTNAME=	elvis
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://www.the-little-red-haired-girl.org/pub/elvis/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}_${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of the ex/vi text editor

LICENSE=	ART10

EXTRACT_AFTER_ARGS=	--exclude guiwin32

DEPRECATED=	Unmaintained since 1999
EXPIRATION_DATE=	2014-04-10
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}"
ALL_TARGET=	all doc/elvtags.man

MAN1=		elvfmt.1 elvis.1 elvtags.1 ref.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# Support building on systems with or without X11 installed.
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
.else
USE_XORG=	xpm
.if defined(WITHOUT_XFT)
CONFIGURE_ARGS+=	--without-xft
.else
USE_XORG=	xft xt
CONFIGURE_ARGS+=	--libs="${LDFLAGS}"
CFLAGS+=	`freetype-config --cflags`
LDFLAGS+=	`freetype-config --libs`
.endif
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Elvis has the following tunable option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITHOUT_X11=yes		Turns off X11 support"
	@${ECHO_MSG} "	WITHOUT_XFT=yes		Turns off Xft support"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g ; \
		 s|-lipc|-lcurses|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS+=|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|FT_FILE|ELVIS_FT_FILE|g' \
	    	${WRKSRC}/guix11/xdialog.c \
		${WRKSRC}/guix11/xdialog.h

do-install:
.for file in elvfmt elvis elvtags ref
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${file}.man ${MANPREFIX}/man/man1/${file}.1
.endfor
	@${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC}/data -cf - . | \
		${TAR} -C ${DATADIR} --unlink -xf -
	@${MKDIR} ${DATADIR}/doc
	${TAR} -C ${WRKSRC}/doc --exclude "*.man" -cf - . | \
		${TAR} -C ${DATADIR}/doc --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

.include <bsd.port.post.mk>
