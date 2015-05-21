# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libexplain
PORTVERSION=	1.3.${PATCHLEVEL}
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library which may be used to explain Unix and Linux system call errors

LICENSE=	LGPL3 # or later
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed
RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof

USES=		bison gettext gmake libtool:build
USE_GHOSTSCRIPT_BUILD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_linux_kd_h=no
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PATCHLEVEL=	D012

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(libdir)/pkgconfig|$$(libdir)/../libdata/pkgconfig|g ; \
		 s|\([[:blank:]]\)sed|\1gsed|g' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libexplain.so

.include <bsd.port.mk>
