# New ports collection makefile for:	gpasm
# Date created:				4 Aug 2000
# Whom:					Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	gpasm
PORTVERSION=	0.9.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sam@inf.enst.fr

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC="cc -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt"

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/gpasm
	${INSTALL_DATA} ${WRKSRC}/doc/gpasm.ps ${PREFIX}/share/doc/gpasm
.endif

.include <bsd.port.mk>
