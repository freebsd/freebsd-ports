# New ports collection makefile for:	libcabinet
# Date Created:				30 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcabinet
PORTVERSION=	0.30
CATEGORIES=	archivers
# mastersites have disappeared as of August 2003.  Perhaps consider
# trying archivers/cabextract instead.
MASTER_SITES=	# http://trill.cis.fordham.edu/~barbacha/cabinet_library/

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable library and utility to use Microsoft cabinet files (.cab)

INSTALLS_SHLIB=	yes

SRCFILE=	${WRKSRC}/listcab.cpp
PROGFILE=	${SRCFILE:S/.cpp$//}

post-build:
	${CXX} ${CXXFLAGS} -o ${PROGFILE} ${SRCFILE} -L${WRKSRC} -lcabinet

pre-su-install:
	${MKDIR} ${PREFIX}/include/cabinet

post-install:
	${INSTALL_PROGRAM} ${PROGFILE} ${PREFIX}/bin

.include <bsd.port.mk>
