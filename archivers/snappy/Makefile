# ex:ts=8
# Ports collection makefile for:	snappy
# Date created:				Apr 3 2011
# Whom:					vanilla@
#
# $FreeBSD$
#

PORTNAME=	snappy
PORTVERSION=	1.0.3
PORTREVISION=	0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A fast compressor/decompressor library

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e \
		'/^install-data-am:/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
