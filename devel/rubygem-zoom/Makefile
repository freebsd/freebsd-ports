# Created by: Mitsuru YOSHIDA <mitsuru@riken.jp>
# $FreeBSD$

PORTNAME=	zoom
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Ruby binding to the Z39.50 Object-Orientation Model (ZOOM)

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

LIB_DEPENDS=	yaz.4:${PORTSDIR}/net/yaz

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

CONFIGURE_ARGS+=	--with-opt-dir="${LOCALBASE}"

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>
