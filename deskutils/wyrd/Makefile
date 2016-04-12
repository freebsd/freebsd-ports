# Created by: Russell A. Jackson <raj@csub.edu>
# $FreeBSD$

PORTNAME=	wyrd
PORTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://pessimization.com/software/wyrd/

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	Text-based front-end to Remind

LICENSE=	GPLv2

RUN_DEPENDS=	remind:deskutils/remind

USES=		gmake ncurses
USE_OCAML=	yes
USE_OCAML_CAMLP4=yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS= CPPFLAGS="${CFLAGS}"
MAKE_ARGS=	 CLIBFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/wyrd etc/wyrdrc man/man1/wyrd.1.gz man/man5/wyrdrc.5.gz
PORTDOCS=	manual.html manual.pdf

OPTIONS_DEFINE=	UTF8 DOCS
UTF8_CONFIGURE_ENABLE=	utf8

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} 's|gcc|${CC}|' ${WRKSRC}/curses/curses.ml

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wyrd.opt ${STAGEDIR}${PREFIX}/bin/wyrd
	${INSTALL_DATA} ${WRKSRC}/wyrdrc ${STAGEDIR}${PREFIX}/etc/wyrdrc
	${INSTALL_MAN} ${WRKSRC}/doc/wyrd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/wyrdrc.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
