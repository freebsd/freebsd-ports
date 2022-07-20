PORTNAME=	Shout
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	http://downloads.us.xiph.org/releases/libshout/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl glue for libshout MP3 streaming source library

LICENSE=	NONE

LIB_DEPENDS=	libshout.so:audio/libshout

USES=		perl5 pkgconfig shebangfix
USE_PERL5=	configure

DOCSDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
SHEBANG_FILES=	*.pl

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -i '' -e 's/CCFLAGS/INC/' ${WRKSRC}/Makefile.PL

post-configure:
	@${PERL} -i -pe '$$_ .= " -lpthread" if /^LDDLFLAGS/;' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Shout/Shout.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/example*.pl ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
