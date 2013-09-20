# $FreeBSD$

PORTNAME=	sablevm
PORTVERSION=	1.13
PORTREVISION=	10
CATEGORIES=	java devel
MASTER_SITES=	SF

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java VM created by McGill University's Sable Research Group

LICENSE=	LGPL21

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt \
		ffi:${PORTSDIR}/devel/libffi
RUN_DEPENDS=	fastjar:${PORTSDIR}/archivers/fastjar

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libltdl
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USES=		pkgconfig gettext iconv

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME}

OPTIONS_DEFINE=	MAN SVMCP
OPTIONS_DEFAULT=MAN SVMCP
MAN_DESC=	Build and install man pages
SVMCP_DESC=	Install SableVM classpath

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMAN}
MAN1=		java-sablevm.1 sablevm.1
.endif

.if ${PORT_OPTIONS:MSVMCP}
RUN_DEPENDS+=	${LOCALBASE}/lib/sablevm-classpath/libjavalang.so:${PORTSDIR}/java/sablevm-classpath
.endif

post-extract:
	@${REINPLACE_CMD} -e 's,^subdirs=".*,,' ${WRKSRC}/configure
.if empty(PORT_OPTIONS:MMAN)
	@${REINPLACE_CMD} -e 's,^\(man_MANS = \).*,\1,' ${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
