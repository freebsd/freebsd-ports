# New ports collection makefile for:	xdeview
# Version Required:	0.5.13
# Date Created:		9 Feb 1997
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $Id$
#

DISTNAME=	uudeview-0.5.13
PKGNAME=	xdeview-0.5.13
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.uni-frankfurt.de/pub/dist/frank/ \
		http://www.uni-frankfurt.de/~fp/uudeview/Apps/frank/ \
		ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/

MAINTAINER=	ac199@freenet.hamilton.on.ca

LIB_DEPENDS=    tk41\\.1\\.:${PORTSDIR}/x11/tk41
BUILD_DEPENDS=	${LOCALBASE}/lib/libuu.a:${PORTSDIR}/devel/uulib
#LIB_DEPENDS=	uu\\.1\\.:${PORTSDIR}/devel/uulib

USE_X11=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl
MAN1=		xdeview.1

PORTDOCDIR?=	share/doc/xdeview
DOCFILES+=	${FILESDIR}/porting.notes ${WRKSRC}/HOWTO

#pre-build:
#	@${CP} ${LOCALBASE}/lib/libuu.so.1.0 ${WRKSRC}/uulib
#	@${TOUCH} ${WRKSRC}/libuu.a
#	@${TOUCH} ${WRKSRC}/uulib/libuu.a

post-install:
	strip ${PREFIX}/bin/uuwish
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Copying documents to ${PREFIX}/${PORTDOCDIR}"
	@${MKDIR} ${PREFIX}/${PORTDOCDIR}
	${INSTALL_MAN} ${DOCFILES} ${PREFIX}/${PORTDOCDIR}
.else
	@${ECHO_MSG} "===>  Not copying available documents"
.endif
	${INSTALL_MAN} ${WRKSRC}/man/xdeview.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
