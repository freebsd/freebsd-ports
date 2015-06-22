# Created by: Sangwoo Shim <sangwoos@gmail.com>
# $FreeBSD$

PORTNAME=	protomol
PORTVERSION=	2.0.3
PORTREVISION=	11
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}/ProtoMol/${PORTVERSION}
DISTFILES=	${DISTNAME}-tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OO, component based, framework for molecular dynamics (MD) simulations

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=	yes
USES=		jpeg
USE_XORG=	xmu xt sm ice xext x11 xi

# Hack to cure a misbehavior of the configure script
CONFIGURE_ARGS+=	--without-irix_mipspro_mpi

CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	GLUT
OPTIONS_DEFAULT=	GLUT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLUT}
CONFIGURE_ARGS+=	--with-glut=yes
USE_GL=	glut
.else
CONFIGURE_ARGS+=	--with-glut=no
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${FIND} . | ${EGREP} -v '\.cvsignore' | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
