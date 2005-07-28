# New ports collection makefile for:	jerm
# Date created:		Jun 25, 2005
# Whom:			Shinsuke Matsui (<smatsui@karashi.org>)
#
# $FreeBSD$
#

PORTNAME=	jerm
PORTVERSION=	8094
CATEGORIES=	comms
MASTER_SITES=	http://www.bsddiary.net/jerm/

MAINTAINER=	smatsui@karashi.org
COMMENT=	Communication terminal through serial and TCP/IP interfaces

MAN1=		jerm.1

OPTIONS=	JUPITER		"With Jupiter support" off

PORTDOCS=	README
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_JUPITER)
PLIST_SUB+=	WITH_JUPITER=""
.else
PLIST_SUB+=	WITH_JUPITER="@comment "
.endif

.if !defined(WITH_JUPITER)
MAKE_ARGS+=	JUPITER_FLAGS=
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS?=|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jerm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tiocdtr ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jerm.1 ${PREFIX}/man/man1
.if defined(WITH_JUPITER)
	@${MKDIR} ${PREFIX}/libexec/jerm
	${INSTALL_SCRIPT} ${WRKSRC}/init.sh ${PREFIX}/libexec/jerm
	${INSTALL_SCRIPT} ${WRKSRC}/rock.pl ${PREFIX}/libexec/jerm
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
