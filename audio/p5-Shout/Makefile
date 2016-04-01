# Created by: leo
# $FreeBSD$

PORTNAME=	Shout
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	http://downloads.us.xiph.org/releases/libshout/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl glue for libshout MP3 streaming source library

LIB_DEPENDS=	libshout.so:audio/libshout

USES=		perl5 pkgconfig shebangfix
USE_PERL5=	configure

DOCSDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
SHEBANG_FILES=	*.pl

MAKE_ENV+=	DESTDIR="${STAGEDIR}"

post-patch:
	${REINPLACE_CMD} -i '' -e 's/CCFLAGS/INC/' ${WRKSRC}/Makefile.PL

post-configure:
	@${PERL} -i -pe '$$_ .= " -lpthread" if /^LDDLFLAGS/;' \
		${WRKSRC}/Makefile

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Shout/Shout.so
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/example*.pl ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
