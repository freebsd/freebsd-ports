# New ports collection makefile for:   exctags
# Version required:    3.4
# Date created:        4 June 1996
# Whom:                jkoshy
#
# $FreeBSD$
#

DISTNAME=	ctags-3.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE}\
		http://fly.hiwaay.net/~darren/archives/ \
		http://people.FreeBSD.org/~jkoshy/PORTS/

MAINTAINER=	jkoshy@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-macro-patterns --disable-etags

MAN1=		exctags.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctags ${PREFIX}/bin/exctags
	${INSTALL_MAN} ${WRKSRC}/ctags.1 ${PREFIX}/man/man1/exctags.1

.include <bsd.port.mk>
