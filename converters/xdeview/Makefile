# New ports collection makefile for:	xdeview
# Date Created:		9 Feb 1997
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $FreeBSD$
#

PORTNAME=	xdeview
PORTVERSION=	0.5.13
CATEGORIES=	converters tk82
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/ \
		http://www.informatik.uni-frankfurt.de/~fp/uudeview/Apps/frank/
DISTNAME=	uudeview-${PORTVERSION}

MAINTAINER=	hoek@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82 \
		uu.1:${PORTSDIR}/converters/uulib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-tcl="${PREFIX}" --enable-tk="${PREFIX}"
# Season to taste --- anything over tcl7.5
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include/tcl8.2 -I${PREFIX}/include/tk8.2"

ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl
MAN1=		xdeview.1

DOCFILES=	${FILESDIR}/porting.notes ${WRKSRC}/HOWTO

post-install:
	strip ${PREFIX}/bin/uuwish
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing documents to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.else
	@${ECHO_MSG} "===>  Not installing available documents"
.endif
	${INSTALL_MAN} ${WRKSRC}/man/xdeview.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
