# New ports collection makefile for:	awele
# Version required:	1.0
# Date created:		01 May 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	awele
PKGNAME=	awele-1.0
CATEGORIES=	games tk80
MASTER_SITES=	http://www-rocq.inria.fr/air/ftp/Jean-Paul/
EXTRACT_SUFX=	1.0.tgz

MAINTAINER=	tg@FreeBSD.org

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
MAN6=		xawele.6

post-patch:
	@/usr/bin/perl -pi -e "s|\@\@LOCALBASE\@\@|${LOCALBASE}|g;" ${WRKSRC}/Imakefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/xawele.man ${PREFIX}/man/man6/xawele.6

.include <bsd.port.mk>
