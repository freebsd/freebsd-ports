# New ports collection makefile for:	google-sparsehash
# Date created:				23 June 2005
# Whom:					Vasil Dimov <vd@datamax.bg>
#
# $FreeBSD$
#

PORTNAME=	google-sparsehash
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	goog-sparsehash
DISTNAME=	sparsehash-${PORTVERSION}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Google's hashtable implementations optimized for space or speed

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if ${OSVERSION} < 500000
# /usr/include/g++/stl_algobase.h:139: template instantiation depth exceeds maximum of 17
# /usr/include/g++/stl_algobase.h:139:  (use -ftemplate-depth-NN to increase the maximum)
CFLAGS+=	-ftemplate-depth-32
.endif

post-patch:
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} -e \
		's|^docdir = .*|docdir = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
.else
	${REINPLACE_CMD} -e \
		'/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

check: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.mk>
