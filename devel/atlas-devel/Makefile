# New ports collection makefile for:	Atlas
# Date created:				3 February 2005
# Whom:					Janni <jannisan@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	Atlas
PORTVERSION=	0.5.94
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=worldforge
DISTNAME=	${PORTNAME}-C++-${PORTVERSION}

MAINTAINER=	jannisan@t-online.de
COMMENT=	A C++ reference implementation of the Atlas protocol

USE_REINPLACE=	YES
USE_LIBTOOL_VER=15
GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES
USE_GCC=	3.4
USE_BZIP2=	YES

CONFIGURE_ARGS+=--program-transform-name=

post-patch:
	@${REINPLACE_CMD} -e '\
		s|\(^pkgconfigdir =\) .*|\1 ${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS THANKS NEWS ChangeLog TODO HACKING ROADMAP
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
