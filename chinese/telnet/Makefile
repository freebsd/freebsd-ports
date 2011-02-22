# New ports collection makefile for:	telnet8
# Date created:		13 Feb 1999
# Whom:			Ching-Hong Wu <woju@freebsd.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	telnet
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	8bit compatible telnet client for Chinese input

MAN1=		zh-telnet.1
PLIST_FILES=	bin/zh-telnet

.include <bsd.port.pre.mk>

.if exists (${SRC_BASE}/contrib/telnet/telnet)
SRCDIR=		${SRC_BASE}/contrib/telnet/telnet
CONTRIB_TELNET=	yes
.elif exists (${SRC_BASE}/usr.bin/telnet)
SRCDIR=		${SRC_BASE}/usr.bin/telnet
.else
IGNORE=		need to build this port with the source code of telnet
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -R ${SRCDIR} ${WRKSRC}
.if defined(CONTRIB_TELNET)
	@${CP} -R ${SRCDIR}/../libtelnet ${SRCDIR}/../../../usr.bin/telnet/Makefile ${WRKSRC}
	@${CP} ${SRCDIR}/../arpa/telnet.h ${SRCDIR}/../../../lib/libtelnet/Makefile ${WRKSRC}/libtelnet
.else
	@${CP} -R ${SRCDIR}/../../lib/libtelnet ${WRKSRC}
.endif

pre-patch:
.if defined(CONTRIB_TELNET)
	@${REINPLACE_CMD} -e 's,/../../contrib/telnet,,g' ${WRKSRC}/Makefile ${WRKSRC}/libtelnet/Makefile
	@${REINPLACE_CMD} -e 's,${TELNETDIR}/telnet,${TELNETDIR},g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/arpa,,g' ${WRKSRC}/libtelnet/Makefile
.endif
	@${REINPLACE_CMD} -e 's,/../../lib,,g' ${WRKSRC}/Makefile

pre-build:
	@cd ${WRKSRC}/libtelnet && ${MAKE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/telnet ${PREFIX}/bin/zh-telnet
	@${INSTALL_MAN} ${WRKSRC}/telnet.1 ${MAN1PREFIX}/man/man1/${MAN1}

.include <bsd.port.post.mk>
