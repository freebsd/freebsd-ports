# New ports collection makefile for:    zh-scim-fcitx
# Date created:		8 May 2007
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	scim
PORTVERSION=	3.1.1
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	SF
PKGNAMESUFFIX=	-fcitx
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An SCIM IMEngine module for fcitx

RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/fcitx

CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib -lintl" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		SCIM_DATADIR=${PREFIX}/share/scim \
		SCIM_ICONDIR=${PREFIX}/share/scim/icons

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
