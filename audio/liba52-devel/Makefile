# New ports collection makefile for:	liba52
# Date created:				Tue Oct 16 10:43:56 BRST 2001
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liba52
PORTVERSION=	0.7.1.b
CATEGORIES=	audio
MASTER_SITES=	http://liba52.sourceforge.net/files/
DISTNAME=	a52dec-${PORTVERSION:S/.b/b/}

MAINTAINER=	lioux@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-oss --enable-shared
USE_LIBTOOL=	yes

MAN1=	a52dec.1 extract_a52.1

.ifndef(WITH_OPTIMIZED_CFLAGS)
USE_AUTOCONF=	yes

EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure.in
.endif

pre-everything::
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} ">>>"
	@${ECHO_MSG} ">>> You can enable extra optimizations by defining WITH_OPTIMIZED_CFLAGS."
	@${ECHO_MSG} ">>> For example, 'make WITH_OPTIMIZED_CFLAGS=yes'"
	@${ECHO_MSG} ">>>"
.endif

post-configure:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/liba52.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
