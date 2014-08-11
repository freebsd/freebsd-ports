# $FreeBSD$

PORTNAME=	sablevm
PORTVERSION=	1.13
PORTREVISION=	10
CATEGORIES=	java devel
MASTER_SITES=	SF

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java VM created by McGill University's Sable Research Group

LICENSE=	LGPL21

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libffi.so:${PORTSDIR}/devel/libffi
RUN_DEPENDS=	fastjar:${PORTSDIR}/archivers/fastjar

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libltdl
USE_LDCONFIG=	yes
USES=		pkgconfig gettext iconv gmake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME}

OPTIONS_DEFINE=	SVMCP
OPTIONS_DEFAULT=SVMCP
SVMCP_DESC=	Install SableVM classpath

SVMCP_RUN_DEPENDS=	${LOCALBASE}/lib/sablevm-classpath/libjavalang.so:${PORTSDIR}/java/sablevm-classpath

post-patch:
	@${REINPLACE_CMD} -e 's,^subdirs=".*,,' ${WRKSRC}/configure

.include <bsd.port.mk>
