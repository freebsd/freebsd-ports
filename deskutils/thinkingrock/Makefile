# New ports collection makefile for:    thinkingrock
# Date created:                         02 Jan 2008
# Whom:                                 Beat Gaetzi <beat@chruetertee.ch>
#
# $FreeBSD$
#

PORTNAME=	thinkingrock
PORTVERSION=	2.0
CATEGORIES=	deskutils java
MASTER_SITES=	SF
DISTNAME=	tr-${PORTVERSION}.epsilon

MAINTAINER=	beat@chruetertee.ch
COMMENT=	Application for collecting and processing your thoughts

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${RM} ${WRKSRC}/bin/thinkingrock.exe
	@${RM} ${WRKSRC}/bin/thinkingrock_w.exe
	@${RM} ${WRKSRC}/bin/thinkingrock.orig
	@${RM} ${WRKSRC}/bin/xdg-email.orig
	@${RM} ${WRKSRC}/bin/xdg-open.orig

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${CP} -r ${WRKSRC}/* ${PREFIX}/${PORTNAME}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${PORTNAME}
	@${LN} -sf ${PREFIX}/${PORTNAME}/bin/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	@${ECHO} bin/${PORTNAME} >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} . ! -type d) | ${SORT} | ${SED} "s|^.|${PORTNAME}|" >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} . -type d) | ${SORT} -r | ${SED} "s|^.|@dirrm ${PORTNAME}|" >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} . -type d -empty) | ${SORT} -r | ${SED} "s|^.|@exec mkdir -p ${PORTNAME}|" >> ${TMPPLIST}

.include <bsd.port.post.mk>
