# New ports collection makefile for:	dmake
# Date created:		31 July 1995
# Whom:			nils@guru.ims.uni-stuttgart.de
#
# $FreeBSD$
#

PORTNAME=	dmake
PORTVERSION=	4.3
CATEGORIES=	devel
MASTER_SITES=	http://people.debian.org/~rene/pkgs/dmake/
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another hyper make utility

GNU_CONFIGURE=	yes
#CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -Wall -Werror"
CONFIGURE_ARGS+=--datadir=${PREFIX}/share/${PORTNAME}
MAN1=		dmake.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/dmake.tf ${PREFIX}/man/man1/dmake.1

.include <bsd.port.mk>
