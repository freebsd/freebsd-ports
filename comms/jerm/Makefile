# Created by: Shinsuke Matsui <smatsui@karashi.org>
# $FreeBSD$

PORTNAME=	jerm
PORTVERSION=	8096
CATEGORIES=	comms
MASTER_SITES=	http://www.bsddiary.net/jerm/

MAINTAINER=	smatsui@karashi.org
COMMENT=	Communication terminal through serial and TCP/IP interfaces

BROKEN=		unfetchable

OPTIONS_DEFINE=	DOCS JUPITER

JUPITER_DESC=	With Jupiter support

OPTIONS_SUB=	yes

PORTDOCS=	README

JUPITER_MAKE_ARGS_OFF=	JUPITER_FLAGS=

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS?=|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|sys/termios.h|termios.h|' \
		${WRKSRC}/tiocdtr.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jerm ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tiocdtr ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/jerm.1 ${STAGEDIR}${PREFIX}/man/man1/

do-install-JUPITER-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/jerm
	${INSTALL_SCRIPT} ${WRKSRC}/init.sh ${STAGEDIR}${PREFIX}/libexec/jerm/
	${INSTALL_SCRIPT} ${WRKSRC}/rock.pl ${STAGEDIR}${PREFIX}/libexec/jerm/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
