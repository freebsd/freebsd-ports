# ex:ts=8
# Ports collection makefile for:	GNU libstdc++
# Version required:			2.8.0
# Date created:				03 Mar 1998
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $Id: Makefile,v 1.1.1.1 1998/03/05 03:37:26 obrien Exp $
#

DISTNAME=	libstdc++-2.8.1
PKGNAME=	glibstdc++-2.8.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	obrien@FreeBSD.org

BUILD_DEPENDS=	gcc28:${PORTSDIR}/lang/gcc28 \
		g++28:${PORTSDIR}/lang/gcc28
RUN_DEPENDS=	${BUILD_DEPENDS}

CC=		gcc28
CXX=		g++28
GNUOSREL!=	uname -r | sed -e 's/[-(].*//'
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST=          ${WRKDIR}/PLIST.fixedup

pre-install:
	${SED} -e 's:%GNUOSREL%:${GNUOSREL}:' ${PKGDIR}/PLIST \
		> ${PLIST}

post-install:
	${RM} -rf ${PREFIX}/lib/gcc-lib/i386-unknown-freebsd${GNUOSREL}/2.8.1/include/g++
	${MV} ${PREFIX}/include/g++  \
		${PREFIX}/lib/gcc-lib/i386-unknown-freebsd${GNUOSREL}/2.8.1/include
	${MV} ${PREFIX}/lib/libiberty.a  \
		${PREFIX}/lib/gcc-lib/i386-unknown-freebsd${GNUOSREL}/2.8.1
	${MV} ${PREFIX}/lib/libstdc++.a  \
		${PREFIX}/lib/gcc-lib/i386-unknown-freebsd${GNUOSREL}/2.8.1

.include <bsd.port.mk>
