# ex:ts=8
# Ports collection makefile for:	GNU libstdc++
# Version required:			2.8.0
# Date created:				03 Mar 1998
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $Id: Makefile,v 1.10 1998/08/17 17:03:31 obrien Exp $
#

DISTNAME=	libstdc++-2.8.1.1
PKGNAME=	glibstdc++-2.8.1.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	obrien@FreeBSD.org

BUILD_DEPENDS=	gcc28:${PORTSDIR}/lang/gcc28 \
		g++28:${PORTSDIR}/lang/gcc28
RUN_DEPENDS=	gcc28:${PORTSDIR}/lang/gcc28 \
		g++28:${PORTSDIR}/lang/gcc28

CC=		gcc28
CXX=		g++28
GCC28DIR=	lib/gcc-lib/i386-unknown-freebsd${OSREL}/2.8.1
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_SUB=	GCC28SUBDIR=${GCC28DIR}

BROKEN_ELF=	depends on gcc28

pre-install:
	@# allow a boched ``make install'' to be re-tried
	@${RM} -rf ${PREFIX}/include/g++
	@${MKDIR} ${PREFIX}/include/g++

post-install:
	${RM} -rf ${PREFIX}/${GCC28DIR}/include/g++
	${MV} ${PREFIX}/include/g++  \
		${PREFIX}/${GCC28DIR}/include
	${MV} ${PREFIX}/lib/libiberty.a  \
		${PREFIX}/${GCC28DIR}
	${MV} ${PREFIX}/lib/libstdc++.a  \
		${PREFIX}/${GCC28DIR}
	${INSTALL_DATA} ${FILESDIR}/osfcn.h  \
		${PREFIX}/${GCC28DIR}/include/g++

.include <bsd.port.mk>
