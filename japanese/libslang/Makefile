# New ports collection makefile for:	ja-S-lang library
# Version required:	1.4.0jp0
# Date created:		3 September 1999
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#

DISTNAME=	slang-1.3.10jp0-20000123
PKGNAME=	ja-libslang-1.4.0.j0
CATEGORIES=	japanese devel
MASTER_SITES=	http://home.sprintmail.com/~kikutani/slang/ \
		http://www.actweb.ne.jp/k-yosino/

PATCH_SITES=	http://www.actweb.ne.jp/k-yosino/
PATCHFILES=	1.3.10jp0__1.4.0jp0.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mega@minz.org

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/slang-1.3.10jp0
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/slang
ALL_TARGET=	all elf
INSTALL_TARGET=	install-elf

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${CP} ${WRKSRC}/slang-j.doc ${PREFIX}/share/doc/slang

.include <bsd.port.mk>
