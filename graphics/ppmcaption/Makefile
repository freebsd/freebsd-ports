# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	ppmcaption
PORTVERSION=	1.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.jwz.org/ppmcaption/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility which adds text to images

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP="${CPP}"
CONFIGURE_ARGS+=	--with-builtin="ncenB24.bdf -scale 0.5 -blur 5"
MAN1=		ppmcaption.1
PLIST_FILES=	bin/ppmcaption

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	does not compile on ia64 or amd64

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e "s,-lang-c89,," ${WRKSRC}/configure

.include <bsd.port.mk>
