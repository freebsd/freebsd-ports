# New ports collection makefile for:	ftnchek
# Date created:		4 May 1998
# Whom:			kargl@apl.washington.edu
#
# $FreeBSD$

PORTNAME=	ftnchek
PORTVERSION=	3.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.dsm.fordham.edu/~ftnchek/download/
MASTER_SITE_SUBDIR=	devel/lang/fortran

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fortran 77 semantic checking utility

MAN1=		dcl2inc.1 ftnchek.1

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS=.*$$|CFLAGS="-DUNIX \$$CFLAGS"|g' ${WRKSRC}/configure

.include <bsd.port.mk>
