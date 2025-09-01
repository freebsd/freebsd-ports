PORTNAME=	genact
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.2
PORTREVISION=	14
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Nonsense activity generator
WWW=		https://github.com/svenstaro/genact

LICENSE=	APACHE20 BSD3CLAUSE ISCL MIT UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	svenstaro

PLIST_FILES=	bin/genact \
		share/man/man1/genact.1.gz

post-install:
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} --print-manpage > ${WRKSRC}/${PORTNAME}.1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
