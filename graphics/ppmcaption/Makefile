# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	ppmcaption
PORTVERSION=	1.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.jwz.org/ppmcaption/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility which adds text to images

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP="${CPP}"
CONFIGURE_ARGS+=	--with-builtin="ncenB24.bdf -scale 0.5 -blur 5"
MAKE_ARGS=	install_prefix=${STAGEDIR}

PLIST_FILES=	bin/ppmcaption man/man1/ppmcaption.1.gz

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	does not compile on ia64 or amd64; untested everywhere else

post-patch:
	${REINPLACE_CMD} -e "s,-lang-c89,," ${WRKSRC}/configure

.include <bsd.port.mk>
