# New ports collection makefile for:	ppmcaption
# Date created:			May 31, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	ppmcaption
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.jwz.org/ppmcaption/

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A utility which adds text to images

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP="${CPP}"
CONFIGURE_ARGS+=	--with-builtin="ncenB24.bdf -scale 0.5 -blur 5"
MAN1=		ppmcaption.1
PLIST_FILES=	bin/ppmcaption
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64 or ia64"
.endif

post-patch:
	${REINPLACE_CMD} -e "s,-lang-c89,," ${WRKSRC}/configure

.include <bsd.port.post.mk>
