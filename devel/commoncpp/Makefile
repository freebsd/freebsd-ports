# New ports collection makefile for:	CommonC++
# Date created:				25 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#
# Copyright (c) 1999-2001 by Open Source Telecom Corporation.
# Verbatim copying and distribution of this entire file is permitted
# in any medium, provided this notice is preserved.

PORTNAME=	CommonC++
PORTVERSION=	1.4.1
CATEGORIES=	devel
MASTER_SITES=	ftp://www.voxilla.org/pub/freebsd/tarball/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cplusplus

MAINTAINER=	dyfet@gnu.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

#post-extract:
#	cd ${WRKSRC} ; ./configure
#	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
#		's|-release \$$\(LT_RELEASE\)||g'

post-install:
	(cd ${WRKSRC} ; make man)
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/commoncpp
	${INSTALL_MAN} ${WRKSRC}/doc/html/* ${PREFIX}/share/doc/commoncpp
.endif

.include <bsd.port.mk>
