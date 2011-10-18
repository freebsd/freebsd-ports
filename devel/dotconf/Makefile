# ex:ts=8
# New ports collection makefile for:   dotconf
# Date created:                Jan 28, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dotconf
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple, powerful configuration-file parser

LICENSE=	LGPL21

USE_GNOME=	gnomehack pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIR/s|=.*|= src|' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for ex in README argdouble caseinsensitive context duplicates errorhandler \
	fallback libpool maketest.sh modules noinline simple
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${ex} ${EXAMPLESDIR})
.endfor
.endif

.include <bsd.port.mk>
