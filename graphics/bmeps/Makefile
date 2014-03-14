# Created by: Hideyuki KURASHINA <rushani@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmeps
PORTVERSION=	2.2.26
CATEGORIES=	graphics perl5
MASTER_SITES=	SF/dktools/dktools/dktools-${PORTVERSION}
DISTNAME=	dktools-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert bitmap images (PNG/JPEG/NetPBM) to EPS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/bsdlic.txt

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

USES=		perl5 zip
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_sys_termios_h=no
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/dktools\
		--libdir=${PREFIX}/lib\
		--includedir=${PREFIX}/include\
		--without-perl\
		--with-lzw
ALL_TARGET=	stc ${PORTNAME}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/bmeps \
		man/man1/bmeps.1.gz \
		%%DATADIR%%/bmeps.str \
		%%DATADIR%%/bmeps.stt.bz2 \
		%%DATADIR%%/bmeps.txt \
		%%DATADIR%%/de/bmeps.stt.bz2 \
		%%DATADIR%%/de/bmeps.txt
PLIST_DIRS=	%%DATADIR%%/de \
		%%DATADIR%%

post-build:
	@(cd ${WRKSRC} && ./stc --/log/stderr/level=error \
		--log/stdout/level=none --/log/file/keep=none \
		bmeps.str share/dktools)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmeps ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/bmeps.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bmeps.str ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/share/dktools/en/bmeps.* ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/de
	${INSTALL_DATA} ${WRKSRC}/share/dktools/de/bmeps.* ${STAGEDIR}${DATADIR}/de

.include <bsd.port.mk>
