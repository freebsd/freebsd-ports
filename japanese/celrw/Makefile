# New ports collection makefile for:	ja-celrw
# Date created:		13 Nov 2001
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	celrw
PORTVERSION=	0.12
CATEGORIES=	japanese misc
MASTER_SITES=	http://www.nurs.or.jp/~kurati/celrw/

MAINTAINER=	shuna@pop16.odn.ne.jp
COMMENT=	Cellular phone-number read/write tool (in Japan only)

WANT_AUTOMAKE_VER=15
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=

pre-configure:
	${RM} -f ${WRKSRC}/install.sh
	${LN} -sf ${AUTOMAKE_DIR}/install-sh ${WRKSRC}/install-sh
	${LN} -sf ${AUTOMAKE_DIR}/config.guess ${WRKSRC}/config.guess
	${LN} -sf ${AUTOMAKE_DIR}/config.sub ${WRKSRC}/config.sub

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/celrw ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
