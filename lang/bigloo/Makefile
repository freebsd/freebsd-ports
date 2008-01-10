# New ports collection makefile for:    bigloo
# Date created:         15 Jul 2002
# Whom:                 Stanislav Grozev <tacho@daemonz.org>
#
# $FreeBSD$
#

PORTNAME=	bigloo
PORTVERSION=	3.0c.4
CATEGORIES=	lang scheme
MASTER_SITES=	ftp://ftp-sop.inria.fr/mimosa/fp/Bigloo/ \
		ftp://kaolin.unice.fr/pub/Bigloo/
DISTNAME=	${PORTNAME}${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Scheme interpreter and native code compiler

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:R}

USE_EMACS=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--emacs=${EMACS_NAME} \
		--lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/bigloo \
		--native=yes \
		--jvm=no
ALL_TARGET=	# empty
INSTALL_TARGET=	install-progs compile-bee install-bee
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/bigloo/${PORTVERSION:R}
PLIST_SUB=	BIGLOO_VERSION="${PORTVERSION:R}"

MAN1=		bigloo.1
INFO=		bigloo

post-patch:
	@${REINPLACE_CMD} -e 's|"-O3"|""|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|"-pthread"|"${PTHREAD_LIBS}"|g' \
		${WRKSRC}/autoconf/pthread
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|g' \
		${WRKSRC}/api/multimedia/src/Unix/bglmixer.c

post-configure:
	@${FIND} ${WRKSRC} -name "bigloo_config.h" | ${XARGS} \
		${REINPLACE_CMD} -e 's/BGL_HAVE_SENDFILE 1/BGL_HAVE_SENDFILE 0/'

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

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
