# New ports collection makefile for:	iip
# Date created:				Sun May 4 07:40:30 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iip
PORTVERSION=	1.1.0
CATEGORIES=	irc security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	invisibleip
EXTRACT_SUFX=	.tgz

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Secure and Anonymous Instant Messaging

USE_REINPLACE=	yes
USE_SIZE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
INSTALL_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=	isproxy.1

DOC_FILES=	AUTHORS CHANGELOG COPYING INSTALL README

do-configure:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|; \
		s|%%DATADIR%%|${DATADIR:S,^${PREFIX}/,,}|' \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh
	@${REINPLACE_CMD} -E \
		-e 's|^(PREFIX).*$$|\1=${PREFIX}|; \
			s|^(CC).*$$|\1=${CC}|; \
			s|^(LD)[[:space:]]*=.*$$|\1=${CC}|; \
			s|^(CFLAGS).*$$|\1+=-g -I. -I..|' \
			${CONFIGURE_WRKSRC}/Makefile

do-install:
# data
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/src/node.ref ${DATADIR}
# doc
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/protocol
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/protocol/* \
		${DOCSDIR}/protocol
.endif # NOPORTDOCS
# man
.for file in ${MAN1}
	@${INSTALL_MAN} ${INSTALL_WRKSRC}/doc/${file} \
		${MAN1PREFIX}/man/man1
.endfor
# sbin
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/src/isproxy \
		${PREFIX}/sbin/isproxy-real
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${PREFIX}/sbin/isproxy

.include <bsd.port.mk>
