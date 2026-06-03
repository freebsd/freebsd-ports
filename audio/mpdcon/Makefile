PORTNAME=	mpdcon
PORTVERSION=	1.5.1
PORTREVISION=	13
CATEGORIES=	audio gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	MPDCon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MPD client for GNUstep
WWW=		https://gap.nongnu.org/mpdcon/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/Documentation/COPYING

LIB_DEPENDS=	libmpdclient.so.2:audio/libmpdclient \
		libSQLClient.so:databases/sqlclient

USES=		gnustep
USE_GNUSTEP=	base gui back build

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	${REINPLACE_CMD} -e \
		's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
			${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
