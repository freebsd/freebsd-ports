# New ports collection makefile for:	landscape
# Date created:			1 May 2001
# Whom:				jon@witchspace.com
#
# $FreeBSD$
#

PORTNAME=		landscape
PORTVERSION=		0.5.1
PORTREVISION=		2
CATEGORIES=     	graphics kde
MASTER_SITES=		http://www.dookie.demon.co.uk/

MAINTAINER=		jon@witchspace.com

LIB_DEPENDS=    	pth.14:${PORTSDIR}/devel/pth

USE_MESA=		yes
USE_KDELIBS_VER=	3

BROKEN=	"Author is working on new version. Coming soon."

post-patch:
	${PERL} -pi.orig -e \
		's,/usr/local,${LOCALBASE},g; \
		 s,/usr/X11R6,${X11BASE},g' ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/landscape ${PREFIX}/bin

post-install:
	strip ${PREFIX}/bin/landscape

.include <bsd.port.mk>
