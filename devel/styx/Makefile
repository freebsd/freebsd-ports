# ex:ts=8
# New ports collection makefile for:	styx
# Date created:			Apr 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	styx
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.speculate.de/styx/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A scanner/parser generator

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_FLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

post-extract:
	@${RM} -f ${WRKSRC}/config.cache

post-patch:
	@${REINPLACE_CMD} -e "s,-lrt,${PTHREAD_LIBS},g" ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC} -cf - doc tutorial | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
.endif

.include <bsd.port.mk>
