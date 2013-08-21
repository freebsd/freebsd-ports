# Created by: Russell A. Jackson <raj@csub.edu>
# $FreeBSD$

PORTNAME=	wyrd
PORTVERSION=	1.4.6
CATEGORIES=	deskutils
MASTER_SITES=	http://pessimization.com/software/wyrd/

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	Text-based front-end to Remind

LICENSE=	GPLv2

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS=	remind:${PORTSDIR}/deskutils/remind

USES=		gmake ncurses
GNU_CONFIGURE=	yes

MAN1=		wyrd.1
MAN5=		wyrdrc.5
PLIST_FILES=	bin/wyrd etc/wyrdrc
PORTDOCS=	manual.html manual.pdf

OPTIONS_DEFINE=	UTF8 DOCS
UTF8_CONFIGURE_ENABLE=	utf8

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wyrd.opt ${PREFIX}/bin/wyrd
	${INSTALL_DATA} ${WRKSRC}/wyrdrc ${PREFIX}/etc/wyrdrc
	${INSTALL_MAN} ${WRKSRC}/doc/wyrd.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/wyrdrc.5 ${MAN5PREFIX}/man/man5
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
