# New ports collection makefile for:	ja-S-lang library
# Version required:	1.3.8_j067
# Date created:		3 September 1999
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#

DISTNAME=	slang-1.3.8__J067
PKGNAME=	ja-libslang-1.3.8.j067
CATEGORIES=	japanese devel
MASTER_SITES=	http://home.sprintmail.com/~kikutani/slang/

MAINTAINER=	mega@minz.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/slang
ALL_TARGET=	all elf
INSTALL_TARGET=	install-elf

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${CP} ${WRKSRC}/slang-j.doc ${PREFIX}/share/doc/slang

.include <bsd.port.mk>
