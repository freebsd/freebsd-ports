# New ports collection makefile for:	xdeview
# Date Created:		9 Feb 1997
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $FreeBSD$
#

PORTNAME=	xdeview
PORTVERSION=	0.5.20
CATEGORIES=	converters tcl84 tk84
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/
DISTNAME=	uudeview-${PORTVERSION}

MAINTAINER=	hoek@FreeBSD.org
COMMENT=	An X11 program for uu/xx/Base64/BinHex/yEnc de-/encoding

LIB_DEPENDS=	uu.3:${PORTSDIR}/converters/uulib \
		tk84.1:${PORTSDIR}/x11-toolkits/tk84

GNU_CONFIGURE=	yes
# Explicitly disable Tcl otherwise the configure script picks-up
# crud from the $PATH lie /usr/opt/Simili/tcl/.
CONFIGURE_ARGS=	--disable-tcl --disable-tk
# Season to taste --- anything better or equal to tcl8.0 is probably okay
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib \
			-lX11 -ltcl84 -ltk84 -lm" \
		CPPFLAGS="-I${LOCALBASE}/include/tcl8.4 -DHAVE_TCL \
			-I${LOCALBASE}/include/tk8.4 -DHAVE_TK \
			-I${X11BASE}/include"

ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl
MAN1=		xdeview.1

DOCFILES=	${FILESDIR}/porting.notes

post-install:
	${STRIP_CMD} ${PREFIX}/bin/uuwish
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing documents to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.else
	@${ECHO_MSG} "===>  Not installing available documents"
.endif
	${INSTALL_MAN} ${WRKSRC}/man/xdeview.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
