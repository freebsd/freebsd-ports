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

GLUT_CONFIGURE_ON=	--with-glut=yes
GLUT_USE=	GL=glut
GLUT_CONFIGURE_OFF=	--with-glut=no

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples ; \
		${COPYTREE_SHARE} .  ${STAGEDIR}${EXAMPLESDIR} "! -name .cvsignore"
.endif

.include <bsd.port.mk>
