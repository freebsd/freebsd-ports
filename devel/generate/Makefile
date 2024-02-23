PORTNAME=	generate
PORTVERSION=	2.8
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.druid.net/darcy/

MAINTAINER=	darcy@druid.net
COMMENT=	Simple text pre-processor
WWW=		https://www.druid.net/darcy/readme-generate.html

USES=		gmake tar:tgz

MAKE_ARGS=	BINDIR=${STAGEDIR}${PREFIX}/bin \
		MANDIR=${STAGEDIR}${PREFIX}/share/man

CONFLICTS_INSTALL=	julius php*-pear-Text_Highlighter

PLIST_FILES=	bin/generate bin/rgenerate share/man/man1/generate.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,^CFLAGS *=,CFLAGS +=,' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
