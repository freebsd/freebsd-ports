# New ports collection makefile for:	korelib
# Date created:				10 May 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	korelib
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.smga3000.com/thekompany/Korelib/

DEPRECATED=	"master site up but distfile not available, last release 2002"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cross-platform C++ library for developing modular applications

USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_AUTOMAKE_VER=14
USE_AUTOCONF_VER=213
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile with gcc 3.4.2"
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.am" | ${XARGS} ${REINPLACE_CMD} -e \
		's|include kore demo|include kore|g ; \
		 s|= -g -O2 -Wall|= @CXXFLAGS@|g'

.include <bsd.port.post.mk>
