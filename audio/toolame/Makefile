# New ports collection makefile for:	tooLAME
# Date created:		Wed May 22 16:53:26 BRT 2002
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	toolame
PORTVERSION=	0.2l
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%200.2/${PORTNAME}%2002l
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optimized mpeg 1/2 layer 2 audio encoder

USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	CC="${CC}" TWEAKS="${CFLAGS}" ARCH="" PG="" OPTIM=""

PLIST_FILES=	bin/toolame
PORTDOCS=	FUTURE HISTORY LGPL.txt README

.include <bsd.port.pre.mk>

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/toolame ${PREFIX}/bin

.include <bsd.port.post.mk>
