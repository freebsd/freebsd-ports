# New ports collection makefile for:	ewipe
# Version required:	0.4.3
# Date created:		17 October 1997
# Whom:			itojun@itojun.org
#
# $Id$
#

DISTNAME=	ewipe0.4.4
PKGNAME=	ewipe-0.4.4
CATEGORIES=	japanese x11
MASTER_SITES=	http://al.ei.tuat.ac.jp/~sekisita/ewipe/

MAINTAINER=	itojun@itojun.org

RUN_DEPENDS=	wish4.2jp:${PORTSDIR}/japanese/tk42

NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/ewipe
	${MKDIR} ${PREFIX}/share/doc/ewipe
	${INSTALL_SCRIPT} ${WRKSRC}/ewipe ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/viewer.tcl ${PREFIX}/lib/ewipe
	${INSTALL_DATA} ${WRKSRC}/tclIndex ${PREFIX}/lib/ewipe
.if !defined(NOPORTDOCS)
	for i in dot.ewipe README Changes ewipe_sample.ewp \
	    ewipe_sample2.ewp; do\
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/ewipe; \
	done
.endif

.include <bsd.port.mk>
