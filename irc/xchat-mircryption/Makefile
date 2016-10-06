# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/irc/xchat-mircryption/Makefile,v 1.2 2006/10/10 20:22:11 mezz Exp $

PORTNAME=	mircryption
DISTVERSION=	0.3.3
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	irc security
MASTER_SITES=	http://mircryption.sourceforge.net/Downloads/
PKGNAMEPREFIX=	xchat-
DISTNAME=	mircryption_xchatsrc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free encryption add-on for the popular XChat irc client

RUN_DEPENDS=	xchat:irc/xchat

USES=		zip dos2unix shebangfix
SHEBANG_FILES=	extras/mcps_masterkey_on_start.pl
ALL_TARGET=	freebsd
CFLAGS+=	-fPIC
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/src/xchat/
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

PLIST_FILES=	lib/xchat/plugins/mircryption.so

PORTDOCS=	README.txt
PORTEXAMPLES=	mcps_masterkey_on_start.pl

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -E \
		-e 's|^(CFLAGS.+)"$$|\1 ${CFLAGS}"|' \
		-e 's|^(LDFLAGS.+)"$$|\1 ${LDFLAGS}"|' \
		-e 's|^(LOAD).*$$|LOAD=${CXX}|' \
		${WRKSRC}/${MAKEFILE}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xchat/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/mircryption.so \
		${STAGEDIR}${PREFIX}/lib/xchat/plugins
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${STAGEDIR}${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} \
		${WRKSRC}/extras/mcps_masterkey_on_start.pl \
		${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
