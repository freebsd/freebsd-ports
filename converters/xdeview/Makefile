# New ports collection makefile for:	xdeview
# Version Required:	0.5.13
# Date Created:		9 Feb 1997
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $Id: Makefile,v 1.4 1997/04/26 23:55:25 asami Exp $
#

DISTNAME=	uudeview-0.5.13
PKGNAME=	xdeview-0.5.13
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.uni-frankfurt.de/pub/dist/frank/ \
		http://www.uni-frankfurt.de/~fp/uudeview/Apps/frank/ \
		ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/

MAINTAINER=	ac199@freenet.hamilton.on.ca

LIB_DEPENDS=    tk41\\.1\\.:${PORTSDIR}/x11/tk41
LIB_DEPENDS=	uu\\.1\\.:${PORTSDIR}/converters/uulib

FILESDIR=	${.CURDIR}/../../converters/uulib/files
USE_X11=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl
MAN1=		xdeview.1

PORTDOCDIR?=	share/doc/xdeview
DOCFILES+=	${FILESDIR}/porting.notes ${WRKSRC}/HOWTO

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
