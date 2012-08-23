# New ports collection makefile for:	graphics/libwpg
# Date created:		2009-01-09
# Whom:			Dima Panov <fluffy@Fluffy.Khv.RU>
#
# $FreeBSD$
#

PORTNAME=	libwpg
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Library and tools to work with WordPerfect Graphics (WPG) files

LICENSE=	LGPL20

LIB_DEPENDS=	wpd-0.9:${PORTSDIR}/textproc/libwpd

USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack ltverhack
USE_BZIP2=	yes
USE_PERL5=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-werror

PORTDOCS=	*

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.else
post-patch:
	@${REINPLACE_CMD} -E '/^SUBDIRS = /s/docs//g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
