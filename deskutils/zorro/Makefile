# New ports collection makefile for:	zorro
# Version required:     1.1p8
# Date created:         03 Aug 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $FreeBSD$
#

DISTNAME=	zorro-1.1p8
PKGNAME=	zorro-1.1.8
CATEGORIES=	deskutils tk82
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/sorted/apps/zorro-1.1p8/

MAINTAINER=	shanee@augusta.de

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zorro ${PREFIX}/bin/zorro
	${MKDIR} ${PREFIX}/share/zorro
	${INSTALL_DATA} ${WRKSRC}/DOTzorrorc ${PREFIX}/share/zorro
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take a look at ${PREFIX}/share/zorro/DOTzorrorc"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
