# New ports collection makefile for:   jmode
# Date created:        26 February 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jmode
PORTVERSION=	0.6.7
PORTREVISION=	6
CATEGORIES=	japanese
MASTER_SITES=	http://downloads.sourceforge.jp/anthy/5467/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	XIM server for Anthy input method

LIB_DEPENDS?=	anthy.1:${PORTSDIR}/japanese/anthy

USE_GNOME=	gnometarget gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.include <bsd.port.post.mk>
