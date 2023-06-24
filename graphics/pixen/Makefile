PORTNAME=	pixen
PORTVERSION=	0.1
PORTREVISION=	11
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/
DISTNAME=	Pixen-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Graphics editing software for small-scale pictures for GNUstep
WWW=		https://www.opensword.org/Pixen/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		tar:bzip2 gnustep
USE_GNUSTEP=	back build

ADDITIONAL_OBJCFLAGS+=	-Dlog2=logb

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Pixen.app/Pixen

.include <bsd.port.mk>
