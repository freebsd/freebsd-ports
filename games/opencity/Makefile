# New ports collection makefile for:	opencity
# Date created:		07 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	opencity
PORTVERSION=	0.0.6.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Stable/${PORTVERSION:C/^([0-9]+\.[0-9]+\.[0-9]+)\..*$/\1/}/
DISTNAME=	${PORTNAME}-${PORTVERSION}stable

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free 3D city simulator

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image net
USE_GL=		gl glu

PORTDOCS=	*

MAN6=		opencity.6

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900027
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src-macros.h
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/install-data-am/ s|install-docsDATA||' \
		${WRKSRC}/docs/Makefile.in
.endif

.include <bsd.port.post.mk>
