# New ports collection makefile for:	konwert
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	konwert
PORTVERSION=	1.8
PORTREVISION=	6
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/${DISTNAME:C/${DISTNAME:C/.//}//}/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHFILES=	${PORTNAME}_${PORTVERSION}-${PORTREVISION}.diff.gz

MAINTAINER=	alexs@snark.rinet.ru
COMMENT=	Modular converter between charsets and filter

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PATCH_WRKSRC=	${WRKDIR}

USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
USE_PERL5=	yes
USE_GMAKE=	yes

MAN1=		konwert.1 trs.1 filterm.1
MANLANG=	"" pl

post-patch:
	@${GREP} -Rl '#\!/bin/bash' ${WRKSRC}/* 2>/dev/null | ${XARGS} \
		${REINPLACE_CMD} -e 's|^#\!/bin/bash|#\!${LOCALBASE}/bin/bash|'

.include <bsd.port.mk>
