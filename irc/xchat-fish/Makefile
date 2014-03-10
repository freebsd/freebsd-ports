# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/irc/xchat-fish/Makefile,v 1.1 2006/10/04 22:30:07 ahze Exp $

PORTNAME=	fish
DISTVERSION=	0.98
PORTREVISION=	4
CATEGORIES=	irc security
MASTER_SITES=	http://wirehack7.opsys.de/FiSH/xchat/ \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/
PKGNAMEPREFIX=	xchat-
DISTNAME=	FiSH-XChat.v${DISTVERSION}-source

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An encryption plugin for XChat

BUILD_DEPENDS=	${LOCALBASE}/lib/libmiracl.a:${PORTSDIR}/math/miracl
RUN_DEPENDS=	xchat:${PORTSDIR}/irc/xchat

USES=		dos2unix zip
NO_WRKSUBDIR=	yes
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
CCFLAGS+=	-Wall -O2 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	CCFLAGS="${CCFLAGS}"

PLIST_FILES=	lib/xchat/plugins/xfish.so
PORTDOCS=	FiSH-xchat.txt \
		FiSH-xchat_History.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	${RM} -f ${WRKSRC}/mir*
	${CP} -pf ${FILESDIR}/Makefile ${WRKSRC}/

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xchat/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/xfish.so \
		${STAGEDIR}${PREFIX}/lib/xchat/plugins/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
