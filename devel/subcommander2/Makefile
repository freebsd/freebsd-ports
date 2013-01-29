# Created by: Naram Qashat
# $FreeBSD$

PORTNAME=	subcommander
PORTVERSION=	2.0.0.b5.2
CATEGORIES=	devel
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION:R:S,.b,~b,}p${PORTVERSION:E}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt4 based multiplatform subversion client, diff & merge tool

BROKEN=		Does not build

LICENSE=	GPLv2

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs \
		svn_client-1:${PORTSDIR}/devel/subversion

LATEST_LINK=	subcommander2
CONFLICTS=	subcommander-1.*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R:S,.b,b,}p${PORTVERSION:E}

USE_DOS2UNIX=	*.cpp *.h
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network qt3support moc_build rcc_build uic_build
QT_NONSTANDARD=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal automake autoheader autoconf
ACLOCAL_ARGS=	-I ac-macros
AUTOMAKE_ARGS=	--with-boost=${LOCALBASE}/include \
		--with-subversion=${LOCALBASE} --with-qt=${QT_PREFIX} \
		--with-apr=${LOCALBASE}/bin/apr-1-config \
		--with-apr-util=${LOCALBASE}/bin/apu-1-config \
		--with-openssl=${OPENSSLBASE}

MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${QT_INCDIR} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${QT_LIBDIR} -L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
