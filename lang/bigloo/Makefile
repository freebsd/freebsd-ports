# New ports collection makefile for:    bigloo
# Date created:         15 Jul 2002
# Whom:                 Stanislav Grozev <tacho@daemonz.org>
#
# $FreeBSD$
#

PORTNAME=	bigloo
PORTVERSION=	3.2b
CATEGORIES=	lang scheme
MASTER_SITES=	ftp://ftp-sop.inria.fr/mimosa/fp/Bigloo/ \
		ftp://kaolin.unice.fr/pub/Bigloo/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Scheme interpreter and native code compiler

LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc

USE_OPENSSL=	yes
USE_GSTREAMER=	yes
USE_EMACS=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--emacs=${EMACS_NAME} \
		--lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/bigloo \
		--native=yes \
		--jvm=no \
		--gclibdir=${LOCALBASE}/lib \
		--gcincdir=${LOCALBASE}/include \
		--customgc=no
ALL_TARGET=	build
INSTALL_TARGET=	install-progs compile-bee install-bee
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/bigloo/${PORTVERSION}
PLIST_SUB=	BIGLOO_VERSION="${PORTVERSION}"

MAN1=		bigloo.1
INFO=		bigloo

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^coflags=|#coflags=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|"-pthread"|"${PTHREAD_LIBS}"|g' \
		${WRKSRC}/autoconf/pthread
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|g' \
		${WRKSRC}/api/multimedia/src/Unix/bglmixer.c

post-configure:
	@${FIND} ${WRKSRC} -name "bigloo_config.h" | ${XARGS} \
		${REINPLACE_CMD} -e 's/BGL_HAVE_SENDFILE 1/BGL_HAVE_SENDFILE 0/'

post-install:
	${INSTALL_MAN} ${WRKSRC}/manuals/bigloo.man ${MANPREFIX}/man/man1/${MAN1}
	${INSTALL_DATA} ${WRKSRC}/manuals/bigloo.info ${PREFIX}/${INFO_PATH}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuals/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuals/*.sui ${DOCSDIR}
.endif

test: build
	@(cd ${WRKSRC}; ${GMAKE} test)

.include <bsd.port.post.mk>
