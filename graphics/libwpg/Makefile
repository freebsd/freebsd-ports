# New ports collection makefile for:	graphics/libwpg
# Date created:		2009-01-09
# Whom:			Dima Panov <fluffy@Fluffy.Khv.RU>
#
# $FreeBSD$
#

PORTNAME=	libwpg
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Library for importing and converting Corel WordPerfect(tm) Graphics images

LIB_DEPENDS=	wpd-0.9.9:${PORTSDIR}/textproc/libwpd

LICENSE=	LGPL20

USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack ltverhack
USE_PERL5=	yes
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.else
post-patch:
	@${REINPLACE_CMD} -E '/^SUBDIRS = /s/docs//g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
