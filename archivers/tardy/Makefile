# Ports collection makefile for:	tardy
# Date created:				Jan 14, 2003
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	tardy
PORTVERSION=	1.24
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/files/${PORTVERSION}/ CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Manipulate the file headers in tar archive files in various ways

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs \
		${LOCALBASE}/include/libiberty/libiberty.h:${PORTSDIR}/devel/gnulibiberty
LIB_DEPENDS=	explain.45:${PORTSDIR}/devel/libexplain

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		tardy.1
PLIST_FILES=	bin/tardy

post-patch:
.for var in CFLAGS LDFLAGS
	@${REINPLACE_CMD} -e 's|^\(${var}\)\ =\ \(.*\)|\1 ?= \2|' \
		${WRKSRC}/Makefile.in
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
