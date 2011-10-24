# New ports collection makefile for:	include
# Date created:		2006-08-05
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	include
PORTVERSION=	0.4.2
CATEGORIES=	devel
MASTER_SITES=	SF/openwince/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	openwince-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of the useful include files for embedded developers

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-install:
	@${FIND} -d ${PREFIX}/include/openwince/ -type f | \
		${SED} -e 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -d ${PREFIX}/include/openwince/ -type d | \
		${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
