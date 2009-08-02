# New ports collection makefile for:	xlslib
# Date created:				13 December 2005
# Whom:					Sergey Prikhodko<sergey@network-asp.biz>
#
# $FreeBSD$
#

PORTNAME=	xlslib
PORTVERSION=	0.2.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergey@network-asp.biz
COMMENT=	A C++ library for generation of Excel(TM) files

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS.*src\).*|\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.include <bsd.port.post.mk>
