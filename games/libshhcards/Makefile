# New ports collection makefile for:	libshhcards
# Version required:			1.0.4
# Date created:				12 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		shhcards-1.0.4
PKGNAME=		libshhcards-1.0.4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			http://home.sol.no/~sverrehu/pub-unix/files/ \
			http://www.freebsd.org/~mph/distfiles/
MASTER_SITE_SUBDIR=	libs/ui

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=		yes
USE_X_PREFIX=		yes
SOLIB=			libshhcards.so

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
SOVERSION=	1
.else
SOVERSION=	1.1
.endif

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/shhcards.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/${SOLIB}.${SOVERSION} ${PREFIX}/lib
	@ ${LN} -sf ${SOLIB}.${SOVERSION} ${PREFIX}/lib/${SOLIB}
	@ ${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/libshhcards
	@ ${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/libshhcards
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libshhcards
.endif

.include <bsd.port.post.mk>
