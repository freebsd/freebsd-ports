# New ports collection makefile for:   rioutil
# Date created:        01 July 2001
# Whom:                greid
#
# $FreeBSD$
#

PORTNAME=       rioutil
PORTVERSION=	1.0.0
CATEGORIES=     audio
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	id3:${PORTSDIR}/audio/id3lib \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

MAN1=		rioutil.1

.include <bsd.port.mk>
