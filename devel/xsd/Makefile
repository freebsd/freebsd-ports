# $FreeBSD$

PORTNAME=	xsd
PORTVERSION=	4.0.0
DISTVERSIONSUFFIX=	+dep
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.codesynthesis.com/download/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	W3C XML Schema to C++ translator

LICENSE=		FLOSSE GPLv2
LICENSE_COMB=		dual
LICENSE_NAME_FLOSSE=	FLOSS Exception
LICENSE_FILE_FLOSSE=	${WRKSRC}/xsd/FLOSSE
LICENSE_PERMS_FLOSSE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/build-0.3/abspath.make:devel/build
# libxsd-frontend should come from a separate port as well, but at the moment
# its distribution as a separate tarball is so poor that it does not even have
# a `make install'.
LIB_DEPENDS=	libcutl.so:devel/libcutl \
		libxerces-c.so:textproc/xerces-c3

OPTIONS_DEFINE=	DOCS EXAMPLES

ALL_TARGET=	# no default target should be passed to gmake.
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKEFILE=	makefile
MAKE_ARGS=	EXTERNAL_LIBCUTL=y \
		install_prefix=${STAGEDIR}${PREFIX} \
		install_man_dir=${STAGEDIR}${MANPREFIX}/man \
		verbose=1
USES=		gmake tar:bzip2

post-patch:
# Use devel/build instead of the port's bundled copy.
	${RM} -fr ${WRKSRC}/build-0.3
	${LN} -s ${LOCALBASE}/include/build-0.3 ${WRKSRC}/build-0.3

post-install:
# Install examples into the right directory.
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${DOCSDIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${RMDIR} ${STAGEDIR}${DOCSDIR}/examples

.include <bsd.port.mk>
