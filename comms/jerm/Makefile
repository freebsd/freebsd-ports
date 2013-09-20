# Created by: Shinsuke Matsui <smatsui@karashi.org>
# $FreeBSD$

PORTNAME=	jerm
PORTVERSION=	8096
CATEGORIES=	comms
MASTER_SITES=	http://www.bsddiary.net/jerm/

MAINTAINER=	smatsui@karashi.org
COMMENT=	Communication terminal through serial and TCP/IP interfaces

MAN1=		jerm.1

OPTIONS_DEFINE=	JUPITER

JUPITER_DESC=	With Jupiter support

PORTDOCS=	README

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJUPITER}
PLIST_SUB+=	WITH_JUPITER=""
.else
PLIST_SUB+=	WITH_JUPITER="@comment "
.endif

.if ! ${PORT_OPTIONS:MJUPITER}
MAKE_ARGS+=	JUPITER_FLAGS=
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS?=|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jerm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tiocdtr ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jerm.1 ${PREFIX}/man/man1
.if ${PORT_OPTIONS:MJUPITER}
	@${MKDIR} ${PREFIX}/libexec/jerm
	${INSTALL_SCRIPT} ${WRKSRC}/init.sh ${PREFIX}/libexec/jerm
	${INSTALL_SCRIPT} ${WRKSRC}/rock.pl ${PREFIX}/libexec/jerm
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
