# New ports collection makefile for:   doxygen
# Date created:        20 March 1998
# Whom:                Joep Grooten <joep@di.nl>
#
# $FreeBSD$
#

PORTNAME=	doxygen
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.stack.nl/~dimitri/doxygen/dl/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	joep@di.nl

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_QT=		yes
USE_PERL5=	yes
MAKE_ENV+=	QTDIR="${X11BASE}" PCFLAGS="${CFLAGS}" PCXXFLAGS="${CXXFLAGS}"
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--prefix ${PREFIX} --perl ${PERL5} --make ${GMAKE}
CONFIGURE_ENV+=	QTDIR=${X11BASE}

pre-configure:
	@${PERL} -pi -e "s:gcc:${CC}:g" ${WRKSRC}/tmake/lib/freebsd-g++/tmake.conf
	@${PERL} -pi -e "s:g\+\+:${CXX}:" ${WRKSRC}/tmake/lib/freebsd-g++/tmake.conf
	@${PERL} -pi -e "s:%%CFLAGS%%:${CFLAGS}:g" ${WRKSRC}/tmake/lib/freebsd-g++/tmake.conf
	@${PERL} -pi -e "s:%%CXXFLAGS%%:${CXXFLAGS}:g" ${WRKSRC}/tmake/lib/freebsd-g++/tmake.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxygen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxytag ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxysearch ${PREFIX}/bin

.include <bsd.port.mk>
