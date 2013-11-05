# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xsd
PORTVERSION=	3.3.0
DISTVERSIONSUFFIX=	-2+dep
CATEGORIES=	devel
MASTER_SITES=	http://www.codesynthesis.com/download/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A W3C XML Schema to C++ translator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/xsd/LICENSE

# FIXME: One could patch all the `#!/usr/bin/env bash' invocations in the build scripts and
#        check if things still work to get rid of the shells/bash dependency.
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	boost_filesystem:${PORTSDIR}/devel/boost-libs \
		xerces-c.3:${PORTSDIR}/textproc/xerces-c3

ALL_TARGET=	# no default target should be passed to gmake.
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKEFILE=	makefile
MAKE_ARGS=	install_prefix=${STAGEDIR}${PREFIX} \
		verbose=1
USES=		gmake
USE_BZIP2=	yes

.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/xsd/documentation/xsd.1 ${STAGEDIR}${MANPREFIX}/man/man1/xsdcxx.1

.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/xsd/documentation && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	${INSTALL_DATA} ${WRKSRC}/xsd/FLOSSE ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/xsd/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/xsd/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/xsd/dist/README-UNIX ${STAGEDIR}${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${FIND} ${WRKSRC}/xsd/examples -type f -name makefile -delete
	(cd ${WRKSRC}/xsd/examples && ${COPYTREE_SHARE} cxx ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
