# New ports collection makefile for:	elvis
# Date created:		1999-09-01
# Whom:			Christian Weisgerber <naddy@unix-ag.uni-kl.de>
#
# $FreeBSD$
#

PORTNAME=	elvis
PORTVERSION=	2.2.0
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/ \
		ftp://ftp.false.com/pub/elvis/ \
		ftp://the.wiretapped.net/pub/elvis/ \
		ftp://ftp.fh-wedel.de/pub/elvis/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}_${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of the ex/vi text editor

EXTRACT_AFTER_ARGS=	| ${TAR} --exclude guiwin32 -xf -

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}"
ALL_TARGET=	all doc/elvtags.man

MAN1=		elvfmt.1 elvis.1 elvtags.1 ref.1

.include <bsd.port.pre.mk>

# Support building on systems with or without X11 installed.
.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=	--without-x
.else
USE_XPM=	yes
.if ${X_WINDOW_SYSTEM:L} == xfree86-3 || defined(WITHOUT_XFT)
CONFIGURE_ARGS+=	--without-xft
.else
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--libs="${LDFLAGS}"
CFLAGS+=	`freetype-config --cflags`
LDFLAGS=	`freetype-config --libs`
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
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g ; \
		 s|-lipc|-lcurses|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS+=|g' ${WRKSRC}/Makefile.in

do-install:
.for file in elvfmt elvis elvtags ref
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${file}.man ${PREFIX}/man/man1/${file}.1
.endfor
	@${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC}/data -cf - . | \
		${TAR} -C ${DATADIR} --unlink -xf -
	@${MKDIR} ${DATADIR}/doc
	${TAR} -C ${WRKSRC}/doc --exclude "*.man" -cf - . | \
		${TAR} -C ${DATADIR}/doc --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

.include <bsd.port.post.mk>
