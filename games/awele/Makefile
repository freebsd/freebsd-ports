# New ports collection makefile for:	awele
# Date created:		01 May 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	awele
PORTVERSION=	1.0
CATEGORIES=	games tk82
MASTER_SITES=	http://www-air.inria.fr/ftp/Jean-Paul/
DISTFILES=	${PORTNAME}1.0.tgz

MAINTAINER=	tg@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/awele
USE_IMAKE=	yes
MAN6=		xawele.6

post-patch:
	${PERL} -pi -e "s|\@\@LOCALBASE\@\@|${LOCALBASE}|g;" ${WRKSRC}/Imakefile

.include <bsd.port.mk>
