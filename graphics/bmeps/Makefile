# Created by: Hideyuki KURASHINA <rushani@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmpp
PORTVERSION=	4.2.2
CATEGORIES=	graphics perl5
MASTER_SITES=	SF/dktools/dktools/dktools-${PORTVERSION}
DISTNAME=	dktools-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert PNG/JPEG/TIFF to PDF/EPS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/bsdlic.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

GNU_CONFIGURE=	yes

# We do not want to include sys/termios.h even if it exists, and we do not want
# to depend on BDB for db.h (it is used by other parts of dktools).
CONFIGURE_ENV=	ac_cv_header_sys_termios_h=no \
		ac_cv_header_db_h=no

ALL_TARGET=	bmpp
USES=		gmake jpeg

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/bmpp

post-patch:
	${REINPLACE_CMD} 's@sz->lsz =@st->lsz =@' ${WRKSRC}/dk3sf.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmpp ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
