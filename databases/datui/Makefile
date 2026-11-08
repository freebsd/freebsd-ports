PORTNAME=	datui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.15
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Data exploration in the terminal
WWW=		https://derekwisong.github.io/datui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo pkgconfig sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	derekwisong

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}-cache.1.gz \
		share/man/man1/${PORTNAME}-catalog.1.gz \
		share/man/man1/${PORTNAME}-completions.1.gz \
		share/man/man1/${PORTNAME}-config.1.gz \
		share/man/man1/${PORTNAME}-formats.1.gz \
		share/man/man1/${PORTNAME}-man.1.gz \
		share/man/man1/${PORTNAME}-theme.1.gz \
		share/man/man1/${PORTNAME}-views.1.gz \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man5/${PORTNAME}-config.5.gz \
		share/man/man7/${PORTNAME}-formats.7.gz \
		share/man/man7/${PORTNAME}-keys.7.gz \
		share/man/man7/${PORTNAME}-query.7.gz

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1 \
		${STAGEDIR}${PREFIX}/share/man/man5 \
		${STAGEDIR}${PREFIX}/share/man/man7
.for sec in 1 5 7
	${INSTALL_MAN} ${WRKSRC}/crates/${PORTNAME}-cli/man/*.${sec} \
		${STAGEDIR}${PREFIX}/share/man/man${sec}
.endfor

.include <bsd.port.mk>
