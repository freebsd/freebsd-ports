# ex:ts=8
# Ports collection makefile for:	fastdep
# Date created:			Oct 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fastdep
PORTVERSION=	0.16
CATEGORIES=	devel
MASTER_SITES=	http://www.irule.be/bvh/c++/fastdep/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Fast dependency generator for C/C++ files

USE_GMAKE=	yes
USE_GETOPT_LONG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-local-gnugetopt
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

DOCS=		AUTHORS CHANGELOG INSTALL README \
		doc/fastdep.html doc/fastdep.pdf doc/c*.htm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastdep ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
