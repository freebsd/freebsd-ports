# New ports collection makefile for:	graphics/libwpg
# Date created:		2009-01-09
# Whom:			Dima Panov <fluffy@Fluffy.Khv.RU>
#
# $FreeBSD$
#

PORTNAME=	libwpg
PORTVERSION=	0.1.3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Library for importing and converting Corel WordPerfect(tm) Graphics images

LIB_DEPENDS=	wpd-0.8.8:${PORTSDIR}/textproc/libwpd

USE_AUTOTOOLS=	libtool:22
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
