# ex:ts=8
# New ports collection makefile for:	libshhopt
# Date created:				11 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	libshhopt
PORTVERSION=	1.1.6
CATEGORIES=	devel
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/
DISTNAME=	shhopt-${PORTVERSION}

MAINTAINER=	obrien@FreeBSD.org

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/libshhopt
	@ ${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/libshhopt
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libshhopt
.endif
	@ ${MKDIR} ${PREFIX}/share/examples/libshhopt
	@ ${INSTALL_DATA} ${FILESDIR}/Makefile ${PREFIX}/share/examples/libshhopt
	@ ${INSTALL_DATA} ${WRKSRC}/example.c ${PREFIX}/share/examples/libshhopt

.include <bsd.port.mk>
