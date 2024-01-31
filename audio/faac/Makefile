PORTNAME=	faac
DISTVERSION=	1.30
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTNAME}-${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION:S/./_/g}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG-2 and MPEG-4 AAC audio encoder
WWW=		https://www.audiocoding.com/

LICENSE=	GPLv2 LGPL21+ ISO
LICENSE_COMB=	multi
LICENSE_NAME_ISO=	ISO/IEC14496
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_FILE_ISO=	${WRKSRC}/README
LICENSE_PERMS_ISO=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		autoreconf compiler:c11 gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
