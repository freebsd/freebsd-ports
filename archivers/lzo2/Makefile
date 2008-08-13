# New ports collection makefile for:	lzo
# Date created:				21 Feb 1998
# Whom:					giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	lzo2
PORTVERSION=	2.03
PORTREVISION=	1
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.oberhumer.com/opensource/lzo/download/ \
		http://fresh.t-systems-sfr.com/unix/src/misc/ \
		http://ftp.uni-koeln.de/util/arc/
MASTER_SITE_SUBDIR=	libs/compression
DISTNAME=	lzo-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	Portable speedy, lossless data compression library

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes

post-build:
	@${ECHO_MSG} "===>  Running self-tests for ${PKGNAME} (can take a few minutes, without output)"
	cd ${WRKSRC} && ${MAKE} test

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,doc/,,' NEWS README
.for i in AUTHORS BUGS COPYING NEWS README THANKS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
	${INSTALL_DATA}	${WRKSRC}/doc/* ${DOCSDIR}/
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/[a-z]*.[ch] ${EXAMPLESDIR}/
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
