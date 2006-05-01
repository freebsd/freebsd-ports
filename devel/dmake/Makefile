# New ports collection makefile for:	dmake
# Date created:		31 July 1995
# Whom:			nils@guru.ims.uni-stuttgart.de
#
# $FreeBSD$
#

PORTNAME=	dmake
PORTVERSION=	4.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another hyper make utility

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
#CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -Wall -Werror"
CONFIGURE_ARGS+=--datadir=${PREFIX}/share/${PORTNAME}
MAN1=		dmake.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/dmake.tf ${PREFIX}/man/man1/dmake.1

.include <bsd.port.mk>
