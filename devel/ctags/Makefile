# New ports collection makefile for:   Exuberant Ctags
# Date created:        4 June 1996
# Whom:                jkoshy
#
# $FreeBSD$
#

PORTNAME=	ctags
PORTVERSION=	5.5.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ctags jkoshy

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	A feature-filled tagfile generator for vi and emacs clones

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-macro-patterns --disable-etags

MAN1=		exctags.1

PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctags ${PREFIX}/bin/exctags
	${INSTALL_MAN} ${WRKSRC}/ctags.1 ${PREFIX}/man/man1/exctags.1
	${MKDIR} ${PREFIX}/include/ctags ${PREFIX}/lib/ctags
	${INSTALL_DATA} ${WRKSRC}/readtags.h ${PREFIX}/include/ctags/
	${INSTALL_DATA} ${WRKSRC}/readtags.o ${PREFIX}/lib/ctags/
	@${SED} 's:%%PREFIX%%:'${PREFIX}':' < ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
