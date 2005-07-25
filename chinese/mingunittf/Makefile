# New ports collection makefile for:	HKSCS Chinese TrueType fonts
# Date created:		29 Nov 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mingunittf
PORTVERSION=	1.08
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	http://www.info.gov.hk/digital21/chi/hkscs/download/
DISTNAME=	ming_uni.ttf
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese Big5HKSCS TrueType fonts

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${TTF}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

TTF=		minguni.ttf

do-install:
	@${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${TTF} ${FONTSDIR}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
