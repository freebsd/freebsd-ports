# ex:ts=8
# Ports collection makefile for:	GNU libstdc++
# Date created:				03 Mar 1998
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

PORTNAME=	glibstdc++
PORTVERSION=	2.8.1.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libstdc++
DISTNAME=	libstdc++-2.8.1.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISO Standard C++ library (includes the STL) for G++ 2.8.0

BUILD_DEPENDS=	gcc28:${PORTSDIR}/lang/gcc28 \
		g++28:${PORTSDIR}/lang/gcc28
RUN_DEPENDS=	gcc28:${PORTSDIR}/lang/gcc28 \
		g++28:${PORTSDIR}/lang/gcc28

NO_CDROM=	'old version, not worth the cost in real estate'

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

CC=		gcc28
CXX=		g++28
.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_TARGET=	i386-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	i386-portbld-freebsdaout${OSREL}
.endif
GCC28DIR=	lib/gcc-lib/${CONFIGURE_TARGET}/2.8.1
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_SUB=	GCC28SUBDIR=${GCC28DIR} GNUHOST=${CONFIGURE_TARGET}

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
