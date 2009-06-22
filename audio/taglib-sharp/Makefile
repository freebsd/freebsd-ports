# New ports collection makefile for:	taglib-sharp
# Date Created:				Aug 25 2008
# Whom:				 	Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	taglib-sharp
PORTVERSION=	2.0.3.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.taglib-sharp.com/Download/ \
		http://download.banshee-project.org/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Tagging library for the Mono framework

LIB_PC_DEPENDS=	mono.pc:${PORTSDIR}/lang/mono

BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|}
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|}

OPTIONS=	DOCS "Install documentation" on

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
		VERSIONSUFX="db62eba44689b5b0"

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"

.if !defined(WITHOUT_DOCS) && !defined(NOPORTDOCS)
#CONFIGURE_ARGS+=	--enable-docs
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

.include <bsd.port.post.mk>
