# New ports collection makefile for:	xlslib
# Date created:				13 December 2005
# Whom:					Sergey Prikhodko<sergey@network-asp.biz>
#
# $FreeBSD$
#

PORTNAME=	xlslib
PORTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergey@network-asp.biz
COMMENT=	A C++ library for generation of Excel(TM) files

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GCC=	3.4+

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS.*src\).*|\1|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^\(CXXFLAGS\).*|\1 = @CXXFLAGS@|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|\(.*class\)\ xlslib_core::\(range\)|\1 \2|' \
		${WRKSRC}/src/xlslib/common.h

.include <bsd.port.mk>
