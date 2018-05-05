# Created by: Jason Evans <jasone@FreeBSD.org>
# $FreeBSD$

PORTNAME=	crux
PORTVERSION=	1.2.0
PORTREVISION=	9
CATEGORIES=	biology python
MASTER_SITES=	http://www.canonware.com/download/Crux/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software toolkit for phylogenetic inference

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06
BROKEN_aarch64=		Fails to link: ImportError: /lib/libgcc_s.so.1: version GCC_4.5.0 required by /usr/local/lib/gcc5/libgfortran.so.3 not found
BROKEN_armv6=		Fails to link: ImportError: /usr/local/lib/gcc49/libgfortran.so.3: Undefined symbol "__aeabi_ldivmod"
BROKEN_armv7=		Fails to link: ImportError: /usr/local/lib/gcc49/libgfortran.so.3: Undefined symbol "__aeabi_ldivmod"

USES=		fortran gmake python tar:bzip2
USE_CSTD=	gnu99
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/lib \
		--with-python=${PYTHON_CMD} \
		--disable-mpi

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		SYS_LINALG

SYS_LINALG_DESC=	Enable system ATLAS/LAPACK
SYS_LINALG_LIB_DEPENDS=	libatlas.so:math/atlas
SYS_LINALG_CONFIGURE_ENABLE=	sys-linalg

post-patch:
	@${REINPLACE_CMD} -e '/altivec/s|-f|-m|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|\([[:blank:]]\)\($$(BINDIR)\)|\1$$(DESTDIR)\2| ; \
		 s|\([[:blank:]]\)\($$(DATADIR)\)|\1$$(DESTDIR)\2| ; \
		 s|\(,\)\(@site_packages@\)|\1$$(DESTDIR)\2| ; \
		 s|\([[:blank:]]\)\(@site_packages@\)|\1$$(DESTDIR)\2|' \
		${WRKSRC}/Makefile.in

post-install:
	@(${FIND} ${STAGEDIR}${PREFIX}/lib/Crux/lib -maxdepth 1 -type f \
		-name "*.so" | ${XARGS} ${STRIP_CMD})
	@(${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -maxdepth 3 -type f \
		-name "*.so" | ${XARGS} ${STRIP_CMD})

.include <bsd.port.mk>
