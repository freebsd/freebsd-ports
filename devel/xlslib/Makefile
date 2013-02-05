# Created by: Sergey Prikhodko<sergey@network-asp.biz>
# $FreeBSD$

PORTNAME=	xlslib
PORTVERSION=	0.2.5
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	sergey@network-asp.biz
COMMENT=	A C++ library for generation of Excel(TM) files

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

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
