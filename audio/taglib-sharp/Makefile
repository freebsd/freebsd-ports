# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	taglib-sharp
PORTVERSION=	2.0.3.7
CATEGORIES=	audio
MASTER_SITES=	http://download.banshee.fm/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Tagging library for the Mono framework

LIB_PC_DEPENDS=	mono.pc:${PORTSDIR}/lang/mono

BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|}
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|}

GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
		VERSIONSUFX="db62eba44689b5b0"

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-docs
.endif

.include <bsd.port.post.mk>
