# New ports collection makefile for:	tkcon
# Date created:         28 Jun 1999
# Whom:                 wghicks@bellsouth.net
#
# $FreeBSD$
#

PORTNAME=	tkcon
PORTVERSION=	1.6
CATEGORIES=	devel tk82
MASTER_SITES=	ftp://ftp.neosoft.com/languages/tcl/sorted/packages-8.0/devel/

MAINTAINER=	gehicks@cisco.com

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

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
