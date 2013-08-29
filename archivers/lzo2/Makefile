# Created by: giffunip@asme.org
# $FreeBSD$

PORTNAME=	lzo2
PORTVERSION=	2.06
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.oberhumer.com/opensource/lzo/download/ \
		LOCAL/mandree
DISTNAME=	lzo-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Portable speedy, lossless data compression library

LICENSE=	GPLv2

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --docdir=${DOCSDIR}
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install-exec install-pkgincludeHEADERS
.endif

post-build:
.if !defined(WITHOUT_CHECKS)
	@${ECHO_MSG} "===>  Running self-tests for ${PKGNAME} (can take a few minutes)"
	@#: override MALLOC_OPTIONS, else tests take excessively long
	cd ${WRKSRC} && ${SETENV} MALLOC_OPTIONS=jz ${MAKE} check test SHELL="${SH} -x"
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,doc/,,' NEWS README
.for i in AUTHORS BUGS COPYING NEWS README THANKS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
	${INSTALL_DATA}	${WRKSRC}/doc/* ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/[a-z]*.[ch] ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
