# Created by: Hideyuki KURASHINA <rushani@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmpp
PORTVERSION=	3.8.2
CATEGORIES=	graphics perl5
MASTER_SITES=	SF/dktools/dktools/dktools-${PORTVERSION}
DISTNAME=	dktools-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert PNG/JPEG/TIFF to PDF/EPS

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/dktools\
		--libdir=${PREFIX}/lib\
		--includedir=${PREFIX}/include\
		--with-gui=no\
		--with-fallback-string-functions=yes
CONFIGURE_ENV=	ac_cv_header_sys_termios_h=no

ALL_TARGET=	bmpp

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/bmpp %%DATADIR%%/bmpp.txt
PLIST_DIRS=	%%DATADIR%%

pre-patch:
	@${REINPLACE_CMD} 's@sz->lsz =@// sz->lsz =@' ${WRKSRC}/dk3sf.c
	@${REINPLACE_CMD} -e 's@#include <dk3conf.h>@#include <stdio.h>@p'\
			  -e 's@#include <stdio.h>@#include <dk3conf.h>@'\
		${WRKSRC}/dk3types.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmpp ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bmpp.txt ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
