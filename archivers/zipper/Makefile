# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	zipper
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	archivers gnustep
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	gap
DISTNAME=	Zipper-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Tool for inspecting the contents of a compressed archive

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-patch:
	cd ${WRKSRC} && ${FIND} . -name "*#*" -exec ${RM} -f -v "{}" ";"

.include <bsd.port.mk>
