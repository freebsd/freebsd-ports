# New ports collection makefile for:	kdissert
# Date created:				2004 06 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdissert
PORTVERSION=	0.2.4
CATEGORIES=	deskutils kde
MASTER_SITES=	http://freehackers.org/~tnagy/kdissert/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE mindmapping tool

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e "s/-O2//g" ${WRKSRC}/configure

.include <bsd.port.mk>
