# Created by: Hideyuki KURASHINA <rushani@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmpp
DISTVERSION=	4.11.1
CATEGORIES=	graphics perl5
MASTER_SITES=	SF/dktools/dktools/dktools-${PORTVERSION}
DISTNAME=	dktools-${PORTVERSION}

MAINTAINER=	takefu@airport.fm
COMMENT=	Convert PNG/JPEG/TIFF to PDF/EPS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/bsdlic.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

CONFLICTS_INSTALL=	dktools[0-9]*

GNU_CONFIGURE=	yes

# We do not want to include sys/termios.h even if it exists, and we do not want
# to depend on BDB for db.h (it is used by other parts of dktools).
CONFIGURE_ENV=	ac_cv_header_sys_termios_h=no\
		ac_cv_header_db_h=no\
		DESTDIR=${STAGEDIR}

USES=		gmake jpeg localbase:ldflags

ALL_TARGET=	bmpp
PLIST_FILES=	bin/bmpp man/man1/bmpp.1.gz

post-patch:
	@${REINPLACE_CMD} 's@sz->lsz =@st->lsz =@' ${WRKSRC}/dk3sf.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmpp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/bmpp.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
