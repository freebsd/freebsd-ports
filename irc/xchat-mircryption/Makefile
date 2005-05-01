# New ports collection makefile for:	XChat encryption
# Date created:		Sat Jan  8 21:48:41 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mircryption
DISTVERSION=	0.1
CATEGORIES=	irc security
MASTER_SITES=	http://mircryption.sourceforge.net/Downloads/
PKGNAMEPREFIX=	xchat-
DISTNAME=	mircryption_xchatsrc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free encryption add-on for the popular XChat irc client

RUN_DEPENDS=	xchat:${PORTSDIR}/irc/xchat2

USE_X_PREFIX=	yes
USE_ZIP=	yes
USE_REINPLACE=	yes
ALL_TARGET=	freebsd
CFLAGS+=	-fPIC

WRKSRC=		${WRKDIR}/mircryption/src/xchat/
#
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

PLIST_DIRS=	\
		%%EXAMPLESDIR%%
PLIST_FILES=	\
		lib/xchat/plugins/mircryption.so \
		%%EXAMPLESDIR%%/mcps_masterkey_on_start.pl

PORTDOCS=	\
		README.txt

post-patch:
# \r\n -> \n
	@${FIND} ${WRKSRC} -type f -exec \
		${REINPLACE_CMD} -E \
		-e 's|||' \
		{} \;
# CFLAGS safeness
# LDFLAGS safeness
# linker safeness
	@${REINPLACE_CMD} -E \
		-e 's|^(CFLAGS.+)"$$|\1 ${CFLAGS}"|' \
		-e 's|^(LDFLAGS.+)"$$|\1 ${LDFLAGS}"|' \
		-e 's|^(LOAD).*$$|LOAD=${CXX}|' \
		${WRKSRC}/${MAKEFILE}
# set perl path if it exists
.ifdef(PERL5)
	@${REINPLACE_CMD} -E \
		-e 's|/usr/bin/perl|${PERL5}|' \
		${WRKSRC}/extras/mcps_masterkey_on_start.pl
.endif

do-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DOCSDIR}
.endif
# plugin
	@${MKDIR} ${PREFIX}/lib/xchat/plugins
	@${INSTALL_PROGRAM} ${WRKSRC}/mircryption.so \
		${PREFIX}/lib/xchat/plugins
# script
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} \
		${WRKSRC}/extras/mcps_masterkey_on_start.pl \
		${EXAMPLESDIR}

.include <bsd.port.mk>
