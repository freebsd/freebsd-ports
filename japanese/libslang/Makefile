# New ports collection makefile for:	ja-S-lang library
# Version required:	1.2.2
# Date created:		26 Jun 1998
# Whom:			Takashi Mega <mega@minz.org>
#
# $Id: Makefile,v 1.2 1998/10/16 04:30:24 jseger Exp $

DISTNAME=	slang1.2.2
PKGNAME=	ja-libslang-1.2.2
CATEGORIES=	japanese devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/

PATCH_SITES=	http://home.sprintmail.com/~kikutani/slang/
PATCHFILES= 	slang1.2.2jp0.pat.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mega@minz.org

GNU_CONFIGURE=	yes
ALL_TARGET=	all elf
INSTALL_TARGET=	install install-elf
WRKSRC=         ${WRKDIR}/slang

post-install:
	${ECHO} "installing documents in ${PREFIX}/share/doc/slang"
	@mkdir -p ${PREFIX}/share/doc/slang
	${CP} -R ${WRKSRC}/doc/* ${PREFIX}/share/doc/slang

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
