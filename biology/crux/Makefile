# Created by: Jason Evans <jasone@FreeBSD.org>
# $FreeBSD$

PORTNAME=	crux
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	biology python
MASTER_SITES=	http://www.canonware.com/download/Crux/

MAINTAINER=	jasone@FreeBSD.org
COMMENT=	Software toolkit for phylogenetic inference

USES=		fortran gmake
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-python=${PYTHON_CMD} --disable-mpi
USE_CSTD=	gnu99
USE_PYTHON=	yes

OPTIONS_DEFINE=	SYS_LINALG
SYS_LINALG_DESC=	Enable system ATLAS/LAPACK

NO_STAGE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSYS_LINALG}
CONFIGURE_ARGS+=	--enable-sys-linalg
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
.else
CONFIGURE_ARGS+=	--disable-sys-linalg
.endif

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not build on powerpc-9: error in pthreads
.endif

post-install:
	@${PREFIX}/bin/crux -b -q /dev/null

.include <bsd.port.mk>
