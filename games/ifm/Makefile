# New ports collection makefile for:	ifm
# Version required:			3.0
# Date created:				Mon Oct 12 12:32:07 EDT 1998
# Whom:					Dave Chapeskie <dchapes@ddm.on.ca>
#
# $Id$
#

DISTNAME=	ifm30
PKGNAME=	ifm-3.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.gmd.de/if-archive/mapping-tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dchapes@ddm.on.ca

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		ifm.1 tkifm.1
#INSTALL_TARGET=	install install-tkifm

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ifm.1 ${WRKSRC}/tkifm/tkifm.1 \
		${PREFIX}/man/man1
	install-info ${PREFIX}/info/ifm.info ${PREFIX}/info/dir
	install-info ${PREFIX}/info/scr2ifm.info ${PREFIX}/info/dir
	install-info ${PREFIX}/info/tkifm.info ${PREFIX}/info/dir

.include <bsd.port.mk>
