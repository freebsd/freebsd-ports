# ex:ts=8
# Ports collection makefile for:	fastdep
# Date created:			Oct 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fastdep
PORTVERSION=	0.14
CATEGORIES=	devel
MASTER_SITES=	http://www.irule.be/bvh/c++/fastdep/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
MAKE_ENV=	CXX="${CXX} -I${LOCALBASE}/include -DHAVE_DECL_GETOPT=1" \
		CXXFLAGS="${CXXFLAGS}"

post-patch:
.for file in Makefile config/link.mk build/dependencies.mk
	@${REINPLACE_CMD} -e 's|g++|\$$\(CXX\)|g ; \
		 s|[\$$][(]CFLAGS[)]||g ; \
		 s|\. -l|\$$\{LOCALBASE\}/lib -l|g' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's|PREFIX=|PREFIX?=|g' ${WRKSRC}/Makefile.options

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastdep ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
