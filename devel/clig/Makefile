# New ports collection makefile for:   clig
# Date created:        27 July 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	clig
PORTVERSION=	1.1.3
CATEGORIES=	devel tcl82
MASTER_SITES=	http://wsd.iitb.fhg.de/~geg/clighome/

MAINTAINER=	billf@FreeBSD.org
COMMENT=	Auto-generate an (argc, argv) processor, usage message, and manpage

# This should work with any version of tcl.  See also ${MAKE_ENV}.
BUILD_DEPENDS=	${LOCALBASE}/bin/tclsh8.2:${PORTSDIR}/lang/tcl82
RUN_DEPENDS=	${LOCALBASE}/bin/tclsh8.2:${PORTSDIR}/lang/tcl82

MAN1=		clig.1

NO_BUILD=	yes
MAKEFILE=	makefile
MAKE_ENV=	tclsh=${PREFIX}/bin/tclsh8.2
PLIST_SUB=	VERSION=${DISTNAME}

do-patch:
	@${CHMOD} a+r ${WRKSRC}/CHANGES
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/makefile.orig
	@${SED} -e 's#prefix =~/tools#prefix =${PREFIX}/share#' \
	       -e 's#LROOT =~/tools#LROOT =${PREFIX}#' \
	       -e 's#DOCDIR =$$(prefix)/doc#DOCDIR =${PREFIX}/share/doc/clig#' \
	       -e 's#MANDIR =$$(prefix)#MANDIR =${MANPREFIX}/man/#' \
		${WRKSRC}/makefile.orig > ${WRKSRC}/makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/WISHLIST ${PREFIX}/share/doc/clig

.include <bsd.port.mk>
