# New ports collection makefile for:	iip
# Date created:				Sun May 4 07:40:30 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iip
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	irc security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED} \
		${MASTER_SITE_LOCAL:S/$/:node_update/}
MASTER_SITE_SUBDIR=	invisibleip \
			lioux/:node_update
EXTRACT_SUFX=	.tgz
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		node-${NODE_REF_VERSION_DATE}.ref.bz2:node_update
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Secure and Anonymous Instant Messaging

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALL_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

DEPRECATED=     'IIP network has been resurrected but it is no\
		longer stable. It should work but be warned. Use\
		at your own risk!'

MAN1=	isproxy.1

NODE_REF_VERSION_DATE=	20050110
DOC_FILES=	AUTHORS CHANGELOG COPYING INSTALL README

post-extract:
	@${BZCAT} \
		${DISTDIR}/${DIST_SUBDIR}/node-${NODE_REF_VERSION_DATE}.ref.bz2 \
		> ${WRKSRC}/node.ref

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
