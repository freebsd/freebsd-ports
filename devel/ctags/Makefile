# New ports collection makefile for:   exctags
# Date created:        4 June 1996
# Whom:                jkoshy
#
# $FreeBSD$
#

PORTNAME=	ctags
PORTVERSION=	5.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ctags jkoshy

MAINTAINER=	jkoshy@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-macro-patterns --disable-etags

MAN1=		exctags.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctags ${PREFIX}/bin/exctags
	${INSTALL_MAN} ${WRKSRC}/ctags.1 ${PREFIX}/man/man1/exctags.1
	${MKDIR} ${PREFIX}/include/ctags ${PREFIX}/lib/ctags
	${INSTALL_DATA} ${WRKSRC}/readtags.h ${PREFIX}/include/ctags/
	${INSTALL_DATA} ${WRKSRC}/readtags.o ${PREFIX}/lib/ctags/

.include <bsd.port.mk>
