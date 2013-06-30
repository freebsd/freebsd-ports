# Created by: ijliao
# $FreeBSD$

PORTNAME=	tardy
PORTVERSION=	1.28
DISTVERSIONSUFFIX=	.D001.orig
CATEGORIES=	archivers
MASTER_SITES=	SF/tardy/${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Manipulate the file headers in tar archive files in various ways

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs \
		${LOCALBASE}/include/libiberty/libiberty.h:${PORTSDIR}/devel/gnulibiberty
LIB_DEPENDS=	explain:${PORTSDIR}/devel/libexplain

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		tardy.1
PLIST_FILES=	bin/tardy

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
BUILD_DEPENDS+=	lzma:${PORTSDIR}/archivers/xz
.endif

post-patch:
.for var in CFLAGS LDFLAGS
	@${REINPLACE_CMD} -e 's|^\(${var}\)\ =\ \(.*\)|\1 ?= \2|' \
		-e '/ps2pdf/d' \
			${WRKSRC}/Makefile.in
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
