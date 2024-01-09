PORTNAME=	japana
PORTVERSION=	2.0.6
PORTREVISION=	2
CATEGORIES=	japanese www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web proxy converting Japanese into Romaji
WWW=		https://www.cgarbs.de/japana.en.html

RUN_DEPENDS=	ja-p5-Text-Kakasi>=2:japanese/p5-Text-Kakasi \
		p5-AppConfig>=0:devel/p5-AppConfig \
		p5-libwww>=0:www/p5-libwww

USES=		perl5 shebangfix
SHEBANG_FILES=	japana

PLIST_FILES=	bin/${PORTNAME} etc/${PORTNAME}.conf.default \
		share/man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/${PORTNAME}* ${WRKSRC}/default.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/default.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.default

.include <bsd.port.mk>
