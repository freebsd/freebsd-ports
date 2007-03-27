# ex:ts=8
# New ports collection makefile for:  mdk
# Date created:			Apr 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdk
PORTVERSION=	1.2.1
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNU:S/$/:gnu/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	${PORTNAME}/v${PORTVERSION}/:gnu \
			${PORTNAME}/:sf
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:gnu \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:sf

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A set of utilities for developing programs using MIX and MIXAL

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile \
		readline.5:${PORTSDIR}/devel/readline

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget libglade2
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

INFO=		mdk

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
