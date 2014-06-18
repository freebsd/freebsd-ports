# Created by: shurd@FreeBSD.org
# $FreeBSD$

PORTNAME=	xnec2c
PORTVERSION=	2.8
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.qsl.net/5b4az/pkg/nec2/xnec2c/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	shurd

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Used to calculate antenna patterns useful to ham radio

LICENSE=	GPLv2

LIB_DEPENDS=	libccm.so:${PORTSDIR}/math/ccmath

GNU_CONFIGURE=	yes
USES=		tar:bzip2 pkgconfig gmake
USE_GNOME=	gtk20

PLIST_FILES=	bin/xnec2c

.include <bsd.port.pre.mk>

post-extract:
	${CP} ${PATCHDIR}/clog.c ${WRKSRC}/src
.if	${OSVERSION} < 900000
	${CP} ${PATCHDIR}/cexp.[ch] ${WRKSRC}/src
.else
	${TOUCH} ${WRKSRC}/src/cexp.c
	${TOUCH} ${WRKSRC}/src/cexp.h
.endif

.include <bsd.port.post.mk>
