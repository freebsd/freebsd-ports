# Created by: Philippe Lefebvre <nemesis@balistik.net>
# $FreeBSD$

PORTNAME=	nano
PORTVERSION=	4.5
CATEGORIES=	editors
MASTER_SITES=	https://www.nano-editor.org/dist/v${PORTVERSION:R}/ GNU

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Nano's ANOther editor, an enhanced free Pico clone

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix ncurses tar:xz

CONFLICTS=	nano-devel-2*

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--docdir=${DOCSDIR} --enable-utf8
CONFIGURE_ENV+=	NCURSESW_CFLAGS="-I${NCURSESINC}" \
		NCURSESW_LIBS="-L${NCURSESLIB} -lncursesw"

MAKE_ARGS+=	install_htmlmanDATA=install-htmlmanDATA

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext localbase
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
