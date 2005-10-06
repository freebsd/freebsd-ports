# New ports collection makefile for:   muh
# Date created:        25 Sept 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	muh
PORTVERSION=	2.2
PORTREVISION=	0
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=muh

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A smart irc-bouncing-tool that remains on IRC all the time

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

.if defined(WITH_IPV6)
CONFIGURE_ARGS=	"--enable-ipv6"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|=muh|=${PREFIX}/bin/muh|g" ${WRKSRC}/misc/muh-check
	@${REINPLACE_CMD} -e "s|||g" ${WRKSRC}/src/ascii.c \
		${WRKSRC}/src/channels.c ${WRKSRC}/src/commands.c \
		${WRKSRC}/src/common.c ${WRKSRC}/src/dcc.c ${WRKSRC}/src/dlink.c \
		${WRKSRC}/src/ignore.c ${WRKSRC}/src/irc.c ${WRKSRC}/src/lexer.c \
		${WRKSRC}/src/log.c ${WRKSRC}/src/match.c ${WRKSRC}/src/muh.c \
		${WRKSRC}/src/parser.c ${WRKSRC}/src/perm.c \
		${WRKSRC}/src/table.c ${WRKSRC}/src/tools.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/muh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/misc/muh-check ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/misc/muh-rotatelog ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/misc/muhrc ${PREFIX}/share/skel/dot.muhrc

.include <bsd.port.mk>
