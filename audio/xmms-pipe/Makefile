# New ports collection makefile for:	xmms-pipe
# Date created:				23 Aug 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-pipe
PORTVERSION=	0.5.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://rooster.stanford.edu/~ben/xmmspipe/
DISTNAME=	xmmspipe-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dyeske@yahoo.com
COMMENT=	Controls XMMS with a named pipe

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GMAKE=	yes
ALL_TARGET=	target

DOC_FILES=	HISTORY README LICENSE COMMANDS

post-patch:
	@${REINPLACE_CMD} -E -e 's|gcc|${CC}|; \
		s|^(COPT=).+$$|\1${CFLAGS} ${PTHREAD_CFLAGS} ${PTHREAD_LIBS}|' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_DATA} ${WRKSRC}/xmmspipe.so \
		${PREFIX}/lib/xmms/General/
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
