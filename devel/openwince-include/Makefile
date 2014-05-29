# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	include
PORTVERSION=	0.4.2
CATEGORIES=	devel
MASTER_SITES=	SF/openwince/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	openwince-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of the useful include files for embedded developers

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes

NO_STAGE=	yes
post-install:
	@${FIND} -d ${PREFIX}/include/openwince/ -type f | \
		${SED} -e 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -d ${PREFIX}/include/openwince/ -type d | \
		${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
