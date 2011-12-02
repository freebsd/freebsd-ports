# New ports collection makefile for:	bmeps
# Date created:				6 Jan 2004
# Whom:					Hideyuki KURASHINA <rushani@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmeps
PORTVERSION=	2.2.22
CATEGORIES=	graphics perl5
MASTER_SITES=	SF/dktools/dktools/dktools-${PORTVERSION}
DISTNAME=	dktools-${PORTVERSION}

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Convert bitmap images (PNG/JPEG/NetPBM) to EPS

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/bsdlic.txt

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		netpbm:${PORTSDIR}/graphics/netpbm \
		png:${PORTSDIR}/graphics/png

USE_ZIP=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes

MAKE_ARGS=	bmeps

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/dktools\
		--with-lzw\
		--libdir=${PREFIX}/lib\
		--includedir=${PREFIX}/include

MAN1=		bmeps.1

do-install:
	@${MKDIR}		${DATADIR}
	@${INSTALL_PROGRAM}	${WRKSRC}/bmeps					${PREFIX}/bin
	@${INSTALL_MAN}		${WRKSRC}/man/man1/bmeps.1			${MANPREFIX}/man/man1
	@${INSTALL_DATA}	${WRKSRC}/bmeps.str				${DATADIR}
	@${INSTALL_DATA}	${WRKSRC}/share/dktools/en/bmeps.stt.bz2	${DATADIR}
	@${INSTALL_DATA}	${WRKSRC}/share/dktools/en/bmeps.txt		${DATADIR}

.include <bsd.port.mk>
