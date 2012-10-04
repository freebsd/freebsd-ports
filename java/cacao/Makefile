# Created by:	Tilman Keskinoz <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cacao
PORTVERSION=	1.6.0
CATEGORIES=	java devel
MASTER_SITES=	http://www.complang.tuwien.ac.at/cacaojvm/download/cacao-${PORTVERSION}/

MAINTAINER=	java@FreeBSD.org
COMMENT=	JIT compiler for JAVA

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/share/classpath/glibj.zip:${PORTSDIR}/java/classpath

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libltdl
USE_GMAKE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_XZ=		yes

MAN1=		cacao.1

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=	--enable-jre-layout
CONFIGURE_ARGS+=	--with-java-runtime-library-prefix=${LOCALBASE}
CONFIGURE_ENV+=		PTHREAD_LIBS="${PTHREAD_LIBS}"

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/cacao/cacao ${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/src/cacao/.libs/libjvm.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/classes/vm.zip ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/man/cacao.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
