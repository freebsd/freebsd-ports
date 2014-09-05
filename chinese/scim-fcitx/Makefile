# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	scim
PORTVERSION=	3.1.1
PORTREVISION=	7
CATEGORIES=	chinese
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-fcitx/${PORTVERSION}
PKGNAMESUFFIX=	-fcitx
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM IMEngine module for fcitx

RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		tar:bzip2 gmake libtool:keepla pkgconfig
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/fcitx

CONFIGURE_ENV+=	SCIM_DATADIR=${PREFIX}/share/scim \
		SCIM_ICONDIR=${PREFIX}/share/scim/icons
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure

.include <bsd.port.mk>
