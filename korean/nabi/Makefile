# New ports collection makefile for:	nabi
# Date created:		5 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nabi
PORTVERSION=	0.8
CATEGORIES=	korean gnome x11
MASTER_SITES=	http://download.kldp.net/nabi/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Hangul X Input Method for Everywhere

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

.if defined(WITH_LAYOUT_390)
CONFIGURE_ARGS=	--with-default-keyboard=39
.elif defined(WITH_LAYOUT_3FINAL)
CONFIGURE_ARGS=	--with-default-keyboard=3f
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == ia64 || ${ARCH} == sparc64
# no appropriate iconv encoding for 64bit wchar_t
VWCHARTENC=	NOPE
.else
VWCHARTENC=	UCS-4-INTERNAL
.endif

post-patch:
	${REINPLACE_CMD} 's,WCHAR_T,${VWCHARTENC},g' \
		${WRKSRC}/src/server.c

.include <bsd.port.post.mk>
