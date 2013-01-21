# Created by: Hideyuki KURASHINA <rushani@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmeps
PORTVERSION=	2.2.26
CATEGORIES=	graphics perl5
MASTER_SITES=	SF/dktools/dktools/dktools-${PORTVERSION}
DISTNAME=	dktools-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert bitmap images (PNG/JPEG/NetPBM) to EPS

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/bsdlic.txt

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff

USE_ZIP=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_sys_termios_h=no
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/dktools\
		--libdir=${PREFIX}/lib\
		--includedir=${PREFIX}/include\
		--without-perl\
		--with-lzw
ALL_TARGET=	stc ${PORTNAME}
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		bmeps.1
PLIST_FILES=	bin/bmeps \
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
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} bmeps ${PREFIX}/bin)
	(cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} bmeps.1 ${MANPREFIX}/man/man1)
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} bmeps.str ${DATADIR})
	(cd ${WRKSRC}/share/dktools/en && ${INSTALL_DATA} bmeps.* ${DATADIR})
	@${MKDIR} ${DATADIR}/de
	(cd ${WRKSRC}/share/dktools/de && ${INSTALL_DATA} bmeps.* ${DATADIR}/de)

.include <bsd.port.mk>
