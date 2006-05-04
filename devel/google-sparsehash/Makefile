# New ports collection makefile for:	google-sparsehash
# Date created:				23 June 2005
# Whom:					Vasil Dimov <vd@datamax.bg>
#
# $FreeBSD$
#

PORTNAME=	google-sparsehash
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	goog-sparsehash
DISTNAME=	sparsehash-${PORTVERSION}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Google's hashtable implementations optimized for space or speed

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e \
		's|$$(prefix)/doc/$$(PACKAGE)-$$(VERSION)|${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e \
		'/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

tests: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
