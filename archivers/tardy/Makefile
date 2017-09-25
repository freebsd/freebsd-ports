# Created by: ijliao
# $FreeBSD$

PORTNAME=	tardy
PORTVERSION=	1.28
DISTVERSIONSUFFIX=	.D001.orig
PORTREVISION=	7
CATEGORIES=	archivers
MASTER_SITES=	SF/tardy/${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Manipulate the file headers in tar archive files in various ways

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs \
		${LOCALBASE}/include/libiberty/libiberty.h:devel/gnulibiberty
LIB_DEPENDS=	libexplain.so:devel/libexplain

GNU_CONFIGURE=	yes
USES=		groff

MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/tardy man/man1/tardy.1.gz

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
.for var in CFLAGS LDFLAGS
	@${REINPLACE_CMD} -e 's|^\(${var}\)\ =\ \(.*\)|\1 ?= \2|' \
		-e '/ps2pdf/d' \
			${WRKSRC}/Makefile.in
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
