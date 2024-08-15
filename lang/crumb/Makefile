PORTNAME=	crumb
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.3
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Crumb programming language
WWW=		https://github.com/liam-ilan/crumb

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	liam-ilan

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@cd ${WRKSRC}/src && \
		${CC} ${CFLAGS} ${LDFLAGS} -lm *.c -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
