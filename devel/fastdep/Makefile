# ex:ts=8
# Ports collection makefile for:	fastdep
# Date created:			Oct 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fastdep
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.irule.be/bvh/c++/fastdep/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"
ALL_TARGET=	boot

post-patch:
	@${REINPLACE_CMD} -e 's|make |\$$\{MAKE\} |g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CXXFLAGS=|CXXFLAGS+=|g ; \
		 s|-O2||g' ${WRKSRC}/Makefile.common

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastdep ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
