# New ports collection makefile for:	XChat fish
# Date created:		Mon Jan 17 03:22:41 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/irc/xchat-fish/Makefile,v 1.1 2006/10/04 22:30:07 ahze Exp $

PORTNAME=	fish
DISTVERSION=	0.98
PORTREVISION=	4
CATEGORIES=	irc security
MASTER_SITES=	http://fish.secure.la/xchat/ \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/
PKGNAMEPREFIX=	xchat-
DISTNAME=	FiSH-XChat.v${DISTVERSION}-source

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An encryption plugin for XChat

BUILD_DEPENDS=	${LOCALBASE}/lib/libmiracl.a:${PORTSDIR}/math/miracl
RUN_DEPENDS=	xchat:${PORTSDIR}/irc/xchat

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
CCFLAGS+=	-Wall -O2 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	CCFLAGS="${CCFLAGS}"

PLIST_FILES=	lib/xchat/plugins/xfish.so
PORTDOCS=	FiSH-xchat.txt \
		FiSH-xchat_History.txt

post-patch:
	@${CP} -pf ${FILESDIR}/Makefile ${WRKSRC}/
	@${RM} -f ${WRKSRC}/mir*
# \r\n -> \n
	@${FIND} ${WRKSRC} -type f -exec \
		${REINPLACE_CMD} -E \
		-e 's|||' \
		{} \;

do-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} \
		${DOCSDIR}/
.endfor
.endif
# plugin
	@${MKDIR} ${PREFIX}/lib/xchat/plugins
	@${INSTALL_PROGRAM} ${WRKSRC}/xfish.so \
		${PREFIX}/lib/xchat/plugins/

.include <bsd.port.mk>
