# New ports collection makefile for:	sourcenav
# Date created:			23 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	sourcenav
PORTVERSION=	5.1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.ORG
COMMENT=	Source code analysis tool

LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83 \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83

PREFIX?=	${LOCALBASE}/sourcenav
USE_BISON=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
NO_MTREE=	yes

post-install:
	@${SED} 's,%%PREFIX%%,${PREFIX},' < ${PKGMESSAGE}

.include <bsd.port.mk>
