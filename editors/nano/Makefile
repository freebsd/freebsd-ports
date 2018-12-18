# Created by: Philippe Lefebvre <nemesis@balistik.net>
# $FreeBSD$

PORTNAME=	nano
PORTVERSION=	3.2
CATEGORIES=	editors
MASTER_SITES=	http://www.nano-editor.org/dist/v${PORTVERSION:R}/ GNU

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Nano's ANOther editor, an enhanced free Pico clone

LICENSE=	GPLv3

USES=		charsetfix ncurses

CONFLICTS=	nano-devel-2*

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--docdir=${DOCSDIR} --enable-utf8
MAKE_ARGS+=	install_htmlmanDATA=install-htmlmanDATA
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

INFO=		nano

PORTSCOUT=	limitw:1,even

.ifdef QEMU_EMULATING
# XXX bug 224740/231346: configure hangs
CONFIGURE_ENV+=	gl_cv_func_printf_enomem=no
.endif

post-patch:
	${REINPLACE_CMD} -e 's/^groff.*/false/' ${WRKSRC}/configure

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample.nanorc ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
.for doc in nano.1.html rnano.1.html nanorc.5.html
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
