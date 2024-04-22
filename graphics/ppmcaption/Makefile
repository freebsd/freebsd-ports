PORTNAME=	ppmcaption
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.jwz.org/ppmcaption/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility which adds text to images
WWW=		https://www.jwz.org/ppmcaption/

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	CPP="${CPP}"
CONFIGURE_ARGS=	--with-builtin="ncenB24.bdf -scale 0.5 -blur 5"
MAKE_ARGS=	install_prefix=${STAGEDIR}

PLIST_FILES=	bin/ppmcaption share/man/man1/ppmcaption.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s,-lang-c89,," ${WRKSRC}/configure

.include <bsd.port.mk>
