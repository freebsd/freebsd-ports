PORTNAME=	nano
DISTVERSION=	8.6
CATEGORIES=	editors
MASTER_SITES=	https://www.nano-editor.org/dist/v${DISTVERSION:R:R}/ GNU

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Nano's ANOther editor, an enhanced free Pico clone
WWW=		https://www.nano-editor.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix ncurses pkgconfig tar:xz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--docdir=${DOCSDIR} --enable-utf8 --mandir=${PREFIX}/share
MAKE_ARGS+=	install_htmlmanDATA=install-htmlmanDATA
PORTSCOUT=	limitw:1,even
INFO=		nano
OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes
NLS_USES=		gettext localbase
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's/^groff.*/false/' ${WRKSRC}/configure

post-install-DOCS-on:
.for doc in nano.1.html rnano.1.html nanorc.5.html
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample.nanorc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
