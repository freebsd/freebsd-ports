# New ports collection makefile for:	Atlas
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	Atlas
PORTVERSION=	0.4.94
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.worldforge.org/pub/worldforge/libs/Atlas-C++/transitional/ \
		http://purple.worldforge.org/wf/downloads/libs/Atlas-C++/transitional/
DISTNAME=	${PORTNAME}-C++-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A C++ reference implementation of the Atlas protocol

USE_REINPLACE=	YES
USE_INC_LIBTOOL_VER=	13
GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES

post-patch:
	@${REINPLACE_CMD} -e 's| install-docDATA | |g' \
		-e 's|\(^pkgconfigdir =\) .*|\1 ${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS THANKS NEWS ChangeLog TODO HACKING ROADMAP
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
