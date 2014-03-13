# Created by: Alex Semenyaka <alex@rinet.ru>
# $FreeBSD$

PORTNAME=	konwert
PORTVERSION=	1.8
PORTREVISION=	11
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/${DISTNAME:C/${DISTNAME:C/.//}//}/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHLEVEL=	11
PATCHFILES=	${PORTNAME}_${PORTVERSION}-${PATCHLEVEL}.diff.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular converter between charsets and filter

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PATCH_WRKSRC=	${WRKDIR}

REINPLACE_ARGS=	-i ""
USES=		perl5 gmake

MAN1=		konwert.1 trs.1 filterm.1
MANLANG=	"" pl

NO_STAGE=	yes
post-patch:
	@${GREP} -Rl '#\!/bin/bash' ${WRKSRC}/* 2>/dev/null | ${XARGS} \
		${REINPLACE_CMD} -e 's|^#\!/bin/bash|#\!${LOCALBASE}/bin/bash|'
	@${FIND} ${WRKSRC} -name '*.orig' -delete

.include <bsd.port.mk>
