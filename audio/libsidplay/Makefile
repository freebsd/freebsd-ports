PORTNAME=	libsidplay
PORTVERSION=	1.36.60
PORTREVISION=	1
CATEGORIES=	audio emulators
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${DISTVERSION}${DISTVERSIONSUFFIX}.orig

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Commodore SID-chip emulator library to play SID music files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool tar:bz2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${CONFIGURE_ARGS_${ARCH}}
CONFIGURE_ENV=	sid_cv_have_ios_binary=yes

INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CONFIGURE_ARGS_i386=	--enable-optendian --enable-optfixpoint

.include <bsd.port.mk>
