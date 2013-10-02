# Created by: Shinsuke Matsui <smatsui@karashi.org>
# $FreeBSD$

PORTNAME=	jerm
PORTVERSION=	8096
CATEGORIES=	comms
MASTER_SITES=	http://www.bsddiary.net/jerm/

MAINTAINER=	smatsui@karashi.org
COMMENT=	Communication terminal through serial and TCP/IP interfaces

OPTIONS_DEFINE=	DOCS JUPITER

JUPITER_DESC=	With Jupiter support

OPTIONS_SUB=	yes

PORTDOCS=	README

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MJUPITER}
MAKE_ARGS+=	JUPITER_FLAGS=
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS?=|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|sys/termios.h|termios.h|' \
		${WRKSRC}/tiocdtr.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jerm ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tiocdtr ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/jerm.1 ${STAGEDIR}${PREFIX}/man/man1/

.if ${PORT_OPTIONS:MJUPITER}
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/jerm
	${INSTALL_SCRIPT} ${WRKSRC}/init.sh ${STAGEDIR}${PREFIX}/libexec/jerm/
	${INSTALL_SCRIPT} ${WRKSRC}/rock.pl ${STAGEDIR}${PREFIX}/libexec/jerm/
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
