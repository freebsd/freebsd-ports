# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/irc/xchat-mircryption/Makefile,v 1.2 2006/10/10 20:22:11 mezz Exp $

PORTNAME=	mircryption
DISTVERSION=	0.3.3
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	irc security
MASTER_SITES=	http://mircryption.sourceforge.net/Downloads/
PKGNAMEPREFIX=	xchat-
DISTNAME=	mircryption_xchatsrc

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A free encryption add-on for the popular XChat irc client

RUN_DEPENDS=	xchat:${PORTSDIR}/irc/xchat

USE_ZIP=	yes
ALL_TARGET=	freebsd
CFLAGS+=	-fPIC
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/src/xchat/
#
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

PLIST_FILES=	lib/xchat/plugins/mircryption.so

PORTDOCS=	README.txt
PORTEXAMPLES=	mcps_masterkey_on_start.pl

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
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} \
		${WRKSRC}/extras/mcps_masterkey_on_start.pl \
		${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
