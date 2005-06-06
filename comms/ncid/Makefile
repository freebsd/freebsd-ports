# New ports collection makefile for:   ncid
# Date created:        06 June 2005
# Whom:                David
#
# $FreeBSD$
#

PORTNAME=	ncid
PORTVERSION=	0.50
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network based Caller ID package

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		ncid.1 ncidscripts.1 ncidtools.1
MAN5=		ncidd.conf.5
MAN8=		ncidd.8

USE_GMAKE=	yes
ALL_TARGET=	freebsd
INSTALL_TARGET=	install-freebsd

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
