# Created by: Sangwoo Shim <sangwoos@gmail.com>
# $FreeBSD$

PORTNAME=	protomol
PORTVERSION=	2.0.3
PORTREVISION=	14
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}/ProtoMol/${PORTVERSION}
DISTFILES=	${DISTNAME}-tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OO, component based, framework for molecular dynamics (MD) simulations

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		jpeg shebangfix xorg
USE_CXXSTD=	c++98
SHEBANG_FILES=	examples/butane_4/procDihedralFile.awk \
		examples/butane_4/cleanOutput.bash \
		examples/butane_4/runButaneResults.sh \
		examples/butane_4/runButaneTests.sh
SHEBANG_LANG=	awk
awk_OLD_CMD=	/usr/bin/gawk
awk_CMD=	/usr/bin/awk # base awk works fine in this case
GNU_CONFIGURE=	yes
USE_XORG=	xmu xt sm ice xext x11 xi

# Hack to cure a misbehavior of the configure script
CONFIGURE_ARGS+=	--without-irix_mipspro_mpi

CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	GLUT EXAMPLES
OPTIONS_DEFAULT=	GLUT

GLUT_CONFIGURE_ON=	--with-glut=yes
GLUT_USES=	gl
GLUT_USE=	GL=glut
GLUT_CONFIGURE_OFF=	--with-glut=no

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples ; \
		${COPYTREE_SHARE} .  ${STAGEDIR}${EXAMPLESDIR} "! -name .cvsignore"

.include <bsd.port.mk>
