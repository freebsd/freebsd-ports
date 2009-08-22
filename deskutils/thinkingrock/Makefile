# New ports collection makefile for:    thinkingrock
# Date created:                         02 Jan 2008
# Whom:                                 Beat Gaetzi <beat@chruetertee.ch>
#
# $FreeBSD$
#

PORTNAME=	thinkingrock
PORTVERSION=	2.2.1
CATEGORIES=	deskutils java
MASTER_SITES=	SF/${PORTNAME}/ThinkingRock/TR%20${PORTVERSION}
DISTNAME=	tr-${PORTVERSION}

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Application for collecting and processing your thoughts

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/bin/tr
	@${RM} ${WRKSRC}/bin/tr.bak
	@${RM} ${WRKSRC}/bin/tr.orig
	@${RM} ${WRKSRC}/bin/tr.exe
	@${RM} ${WRKSRC}/bin/tr_w.exe

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${CP} -r ${WRKSRC}/* ${PREFIX}/${PORTNAME}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${PORTNAME}
	@${LN} -sf ${PREFIX}/${PORTNAME}/bin/tr ${PREFIX}/bin/${PORTNAME}
	@${LN} -sf ${PREFIX}/${PORTNAME}/bin/xdg-email ${PREFIX}/bin/xdg-email
	@${LN} -sf ${PREFIX}/${PORTNAME}/bin/xdg-open ${PREFIX}/bin/xdg-open
	@${ECHO} bin/${PORTNAME} >> ${TMPPLIST}
	@${ECHO} bin/xdg-email >> ${TMPPLIST}
	@${ECHO} bin/xdg-open >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} . ! -type d) | ${SORT} | ${SED} "s|^.|${PORTNAME}|" >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} . -type d) | ${SORT} -r | ${SED} "s|^.|@dirrm ${PORTNAME}|" >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} . -type d -empty) | ${SORT} -r | ${SED} "s|^.|@exec mkdir -p ${PORTNAME}|" >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
