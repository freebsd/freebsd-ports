# New ports collection makefile for:   protomol
# Date created:         5 May 2006
# Whom:                 Sangwoo Shim <sangwoos@gmail.com>
#
# $FreeBSD$

PORTNAME=	protomol
PORTVERSION=	2.0.3
PORTREVISION=	4
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}/ProtoMol/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-tar.gz
EXTRACT_SUFX=	# nada

MAINTAINER=	sangwoos@gmail.com
COMMENT=	OO, component based, framework for molecular dynamics (MD) simulations

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=	yes

# Hack to cure a misbehavior of the configure script
CONFIGURE_ARGS+=	--without-irix_mipspro_mpi

CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}"

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	GLUT "Use glut" on

.include <bsd.port.pre.mk>

.if defined(WITH_GLUT)
CONFIGURE_ARGS+=	--with-glut=yes
USE_GL=	glut
.else
CONFIGURE_ARGS+=	--with-glut=no
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${FIND} . | ${EGREP} -v '\.cvsignore' | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
