# New ports collection makefile for:	ja-S-lang library
# Version required:	1.2.2_j055
# Date created:		22 April 1999
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#

DISTNAME=	slang1.2.2_j055
PKGNAME=	ja-libslang-1.2.2.j055
CATEGORIES=	japanese devel
MASTER_SITES=	http://home.sprintmail.com/~kikutani/slang/

MAINTAINER=	mega@minz.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/slang
ALL_TARGET=	all elf
INSTALL_TARGET=	install install-elf
WRKSRC=		${WRKDIR}/slang

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${ECHO} "===> Installing documents in ${PREFIX}/share/doc/slang"
	@${MKDIR} ${PREFIX}/share/doc/slang
	${CP} -R ${WRKSRC}/doc/* ${PREFIX}/share/doc/slang
	${CP} ${WRKSRC}/slang-j.doc ${PREFIX}/share/doc/slang

.include <bsd.port.mk>
