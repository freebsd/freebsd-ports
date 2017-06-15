# $FreeBSD$

PORTNAME=	sablevm
PORTVERSION=	1.13
PORTREVISION=	12
CATEGORIES=	java devel
MASTER_SITES=	SF

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java VM created by McGill University's Sable Research Group

LICENSE=	LGPL21

LIB_DEPENDS=	libpopt.so:devel/popt \
		libffi.so:devel/libffi \
		libltdl.so:devel/libltdl
RUN_DEPENDS=	fastjar:archivers/fastjar

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gettext gmake iconv libtool pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	SVMCP
OPTIONS_DEFAULT=SVMCP
SVMCP_DESC=	Install SableVM classpath

SVMCP_RUN_DEPENDS=	${LOCALBASE}/lib/sablevm-classpath/libjavalang.so:java/sablevm-classpath

post-patch:
	@${REINPLACE_CMD} -e 's,^subdirs=".*,,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^sablevm_LDADD =/s/$$/ -lpopt/' \
		${WRKSRC}/src/sablevm/Makefile.in

.include <bsd.port.mk>
