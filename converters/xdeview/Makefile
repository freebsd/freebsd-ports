# New ports collection makefile for:	xdeview
# Version Required:	0.5.13
# Date Created:		9 Feb 1997
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $Id: Makefile,v 1.13 1998/06/14 17:50:49 hoek Exp $
#

DISTNAME=	uudeview-0.5.13
PKGNAME=	xdeview-0.5.13
CATEGORIES=	converters tk80
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/ \
		http://www.informatik.uni-frankfurt.de/~fp/uudeview/Apps/frank/

MAINTAINER=	hoek@FreeBSD.ORG

LIB_DEPENDS=    tk80\\.1\\.:${PORTSDIR}/x11-toolkits/tk80 \
		uu\\.1\\.:${PORTSDIR}/converters/uulib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-tcl="${PREFIX}" --enable-tk="${PREFIX}"
# Season to taste --- anything over tcl7.5
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include/tcl8.0 -I${PREFIX}/include/tk8.0"

ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl
MAN1=		xdeview.1

PORTDOCDIR?=	share/doc/xdeview
DOCFILES=	${FILESDIR}/porting.notes ${WRKSRC}/HOWTO

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
