# New ports collection makefile for:	snooper
# Date created:		4 May 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	snooper
PORTVERSION=	1999.12.02
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.alaskaparadise.com/freebsd/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Serial line protocol analyzer (need two serial interfaces)

WRKSRC=		${WRKDIR}/${PORTNAME}/build

GNU_CONFIGURE=	yes
MAKE_ARGS=	OPTFLAG=""
PLIST_FILES=	bin/snooper

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

post-extract:
	@${RM} -f ${WRKSRC}/.depend

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.mk>
