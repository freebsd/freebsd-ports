# New ports collection makefile for:	tkcon
# Version required:     1.6
# Date created:         28 Jun 1999
# Whom:                 wghicks@bellsouth.net
#
# $FreeBSD$
#

DISTNAME=	tkcon-1.6
CATEGORIES=	devel tk80
MASTER_SITES=	ftp://ftp.neosoft.com/languages/tcl/sorted/devel/

MAINTAINER=	wghicks@bellsouth.net

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e 's:/usr/local:${PREFIX}:' ${WRKSRC}/tkcon.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkcon.tcl ${PREFIX}/bin/tkcon

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tkcon
	${INSTALL_DATA} ${WRKSRC}/README.txt $(PREFIX)/share/doc/tkcon/README.tkcon
	${INSTALL_DATA} ${WRKSRC}/docs/* $(PREFIX)/share/doc/tkcon
.endif

.include <bsd.port.mk>
