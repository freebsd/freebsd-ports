# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	vultures
PORTVERSION=	2.1.0
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://www.darkarts.co.za/projects/vultures/attachment/wiki/downloads/${PORTVERSION}/
PKGNAMESUFFIX=	-eye
DISTFILES=	${DISTNAME}-full${EXTRACT_SUFX}?format=raw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical interface for NetHack 3.4.3 forked from Falcon's Eye

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

USE_GMAKE=	yes
USE_SDL=	sdl mixer ttf
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/nethack
HAS_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/sys/unix
CONFIGURE_SCRIPT=	setup.sh
DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
CFLAGS+=	-I${LOCALBASE}/include/libpng15
MAKE_ENV+=	DATADIR="${DATADIR}" MAKE="${GMAKE}" BASECFLAGS="${CFLAGS}"
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
pre-configure:
	@${CHMOD} 755 ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
