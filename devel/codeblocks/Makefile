# Created by: Matthias Sund <m.sund@arcor.de>
# $FreeBSD$

PORTNAME=	codeblocks
PORTVERSION=	13.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Sources/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Open source, cross-platform, free C/C++ IDE

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell \
		librsync.so:${PORTSDIR}/net/librsync

USES=		compiler desktop-file-utils fam:gamin pathfix pkgconfig shared-mime-info
USE_WX=		2.8
WANT_UNICODE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-std=c++0x
.endif

CONFIGURE_ARGS+=	--with-wx-config=${WX_CONFIG} --with-contrib-plugins=all

.include <bsd.port.post.mk>
