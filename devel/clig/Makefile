# New ports collection makefile for:   clig
# Version required:    1.0.2
# Date created:        27 July 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.4 1998/09/23 22:59:23 hoek Exp $
#

DISTNAME=	clig-1.0.2
CATEGORIES=	devel tcl80
MASTER_SITES=	http://wsd.iitb.fhg.de/~kir/clighome/

MAINTAINER=	billf@FreeBSD.org

# This should work with any version of tcl.  See also ${MAKE_ENV}.
BUILD_DEPENDS=	${PREFIX}/bin/tclsh8.0:${PORTSDIR}/lang/tcl80
RUN_DEPENDS=	${PREFIX}/bin/tclsh8.0:${PORTSDIR}/lang/tcl80

MAN1=		clig.1

NO_BUILD=	yes
MAKEFILE=	makefile
MAKE_ENV=	tclsh=${PREFIX}/bin/tclsh8.0

do-patch:
	chmod a+r ${WRKSRC}/CHANGES
	${MV} ${WRKSRC}/makefile ${WRKSRC}/makefile.orig
	${SED} -e 's#prefix =~/tools#prefix =${PREFIX}/share#' \
	       -e 's#LROOT =~/tools#LROOT =${PREFIX}#' \
	       -e 's#DOCDIR =$$(prefix)/doc#DOCDIR =${PREFIX}/share/doc/clig#' \
	       -e 's#MANDIR =$$(prefix)#MANDIR =${MANPREFIX}/man/#' \
		${WRKSRC}/makefile.orig > ${WRKSRC}/makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/WISHLIST ${PREFIX}/share/doc/clig

.include <bsd.port.mk>
