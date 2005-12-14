# New ports collection makefile for:	ftnchek
# Date created:		4 May 1998
# Whom:			kargl@apl.washington.edu
#
# $FreeBSD$

PORTNAME=	ftnchek
PORTVERSION=	3.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.dsm.fordham.edu/~ftnchek/download/
MASTER_SITE_SUBDIR=	devel/lang/fortran

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fortran 77 semantic checking utility

MAN1=		dcl2inc.1 ftnchek.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
MAKE_ARGS=	OPT="${CFLAGS}" CC="${CC}"

.include <bsd.port.mk>
