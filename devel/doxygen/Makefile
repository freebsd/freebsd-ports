# New ports collection makefile for:   doxygen
# Version required:    0.4
# Date created:        20 March 1998
# Whom:                Joep Grooten <joep@di.nl>
#
# $FreeBSD$
#

DISTNAME=	doxygen-0.4.src
PKGNAME=	doxygen-0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.stack.nl/~dimitri/doxygen/dl/

MAINTAINER=	joep@di.nl

WRKSRC=		${WRKDIR}/doxygen-0.4

USE_QT=		yes
USE_PERL5=	yes
MAKE_ARGS=	freebsd-g++
MAKE_ENV+=	CC="${CC}" CXX="${CXX}"

pre-configure:
	${PERL} -pi -e "s:gcc:${CC}:g" ${WRKSRC}/tmake/lib/freebsd-g++/tmake.conf
	${PERL} -pi -e "s:g\+\+:\${CXX}:g" ${WRKSRC}/tmake/lib/freebsd-g++/tmake.conf

do-configure:
	cd ${WRKSRC}/src; \
	${MAKE} tmake \
	TMAKE=../tmake/bin/tmake \
	TMAKEPATH=../tmake/lib/freebsd-g++ \
	PERL=${PERL}

do-build:
	@(cd ${WRKSRC}/src; ${MAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxygen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxytag ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxysearch ${PREFIX}/bin

.include <bsd.port.mk>
