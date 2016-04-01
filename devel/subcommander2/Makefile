# Created by: Naram Qashat
# $FreeBSD$

PORTNAME=	subcommander
PORTVERSION=	2.0.0.b5.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION:R:S,.b,~b,}p${PORTVERSION:E}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt4 based multiplatform subversion client, diff & merge tool

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libsvn_client-1.so:devel/subversion

CONFLICTS=	subcommander-1.*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R:S,.b,b,}p${PORTVERSION:E}

USES=		autoreconf gmake dos2unix
DOS2UNIX_GLOB=	*.cpp *.h
USE_QT4=	corelib gui network qt3support moc_build rcc_build uic_build
QT_NONSTANDARD=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include \
		--with-subversion=${LOCALBASE} --with-qt=${QT_PREFIX} \
		--with-apr=${LOCALBASE}/bin/apr-1-config \
		--with-apr-util=${LOCALBASE}/bin/apu-1-config \
		--with-openssl=${OPENSSLBASE}

CPPFLAGS+=	-I${QT_INCDIR} -I${LOCALBASE}/include
LDFLAGS+=	-L${QT_LIBDIR} -L${LOCALBASE}/lib

.include <bsd.port.mk>
