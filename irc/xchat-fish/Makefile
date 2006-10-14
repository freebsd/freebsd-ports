# New ports collection makefile for:	XChat fish
# Date created:		Mon Jan 17 03:22:41 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/irc/xchat-fish/Makefile,v 1.1 2006/10/04 22:30:07 ahze Exp $

PORTNAME=	fish
DISTVERSION=	0.97a
PORTREVISION=	1
CATEGORIES=	irc security
MASTER_SITES=	http://fish.sekure.us/xchat/
PKGNAMEPREFIX=	xchat-
DISTNAME=	FiSH-xchat.v${DISTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An encryption plugin for XChat

BUILD_DEPENDS=	${LOCALBASE}/lib/libmiracl.a:${PORTSDIR}/math/miracl
RUN_DEPENDS=	xchat:${PORTSDIR}/irc/xchat

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

#
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

PLIST_FILES=	\
		lib/xchat/plugins/xfish.so

PORTDOCS=	\
		FiSH-xchat.txt \
		FiSH-xchat_History.txt

post-patch:
# \r\n -> \n
	@${FIND} ${WRKSRC} -type f -exec \
		${REINPLACE_CMD} -E \
		-e 's|||' \
		{} \;
# CC safeness
# CFLAGS safeness
	@${REINPLACE_CMD} -E \
		-e 's|gcc|${CC}|' \
		-e 's|-O2|${CFLAGS}|' \
		-e 's|-shared|-shared -fPIC -DPIC|' \
		-e 's|miracl.a|${LOCALBASE}/lib/libmiracl.a|' \
		${WRKSRC}/make*

do-build:
	@cd ${WRKSRC} && ${SH} ./make_all

do-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} \
		${DOCSDIR}
.endfor
.endif
# plugin
	@${MKDIR} ${PREFIX}/lib/xchat/plugins
	@${INSTALL_PROGRAM} ${WRKSRC}/xfish.so \
		${PREFIX}/lib/xchat/plugins

.include <bsd.port.mk>
