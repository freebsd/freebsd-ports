# ex:ts=8
# Ports collection makefile for:	GNU libstdc++
# Version required:			2.8.1.1
# Date created:				03 Mar 1998
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $Id: Makefile,v 1.13 1998/11/11 05:37:25 asami Exp $
#

DISTNAME=	libstdc++-2.8.1.1
PKGNAME=	glibstdc++-2.8.1.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libstdc++

MAINTAINER=	obrien@FreeBSD.org

BUILD_DEPENDS=	gcc28:${PORTSDIR}/lang/gcc28 \
		g++28:${PORTSDIR}/lang/gcc28
RUN_DEPENDS=	gcc28:${PORTSDIR}/lang/gcc28 \
		g++28:${PORTSDIR}/lang/gcc28

.include <bsd.port.pre.mk>

CC=		gcc28
CXX=		g++28
.if ${PORTOBJFORMAT} == "elf"
GNUHOST=        i386-unknown-freebsdelf${OSREL}
.else
GNUHOST=        i386-unknown-freebsd${OSREL}
.endif
GCC28DIR=	lib/gcc-lib/${GNUHOST}/2.8.1
CONFIGURE_ARGS= --host=${GNUHOST}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_SUB=	GCC28SUBDIR=${GCC28DIR} GNUHOST=${GNUHOST}

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

.include <bsd.port.post.mk>
