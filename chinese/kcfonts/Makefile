# Created by: Ming-I Hseh <PA@FreeBSD.Ntu.edu.TW>
# $FreeBSD$

PORTNAME=	kcfonts
PORTVERSION=	1.05
PORTREVISION=	3
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kuo Chauo Chinese Fonts collection

USES=		fonts
BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

MAKE_ARGS=	CFONTDIR=${FONTSDIR} EFONTDIR=${FONTSDIR}
MAKE_JOBS_UNSAFE=yes
BROKEN_sparc64=		Does not build on sparc64

NO_WRKSUBDIR=	yes

pre-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
