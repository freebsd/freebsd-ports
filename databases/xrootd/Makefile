PORTNAME=	xrootd
DISTVERSION=	4.10.0
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://xrootd.org/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for fast, low latency, scalable data access
WWW=		http://xrootd.org/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake cpe gnome localbase:ldflags pkgconfig readline shebangfix ssl
SHEBANG_GLOB=	*.sh
SHEBANG_FILES=	utils/cms_monPerf
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR:STRING=${PREFIX}/lib \
		-DCMAKE_INSTALL_BINDIR:STRING=${PREFIX}/bin \
		-DCMAKE_INSTALL_INCLUDEDIR:STRING=${PREFIX}/include \
		-DCMAKE_INSTALL_DATADIR:STRING=${DATADIR}

CXXFLAGS+=	-Ddirent64=dirent
LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=	KERBEROS5
OPTIONS_SUB=	yes

KERBEROS5_CMAKE_BOOL=	ENABLE_KRB5
KERBEROS5_BROKEN=	build picks base kerberos, but needs the port one (problem only exists in poudriere builds for some reason)
KERBEROS5_LIB_DEPENDS=	libkrb5.so:security/krb5

.include <bsd.port.pre.mk>

.if ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl} || ${SSL_DEFAULT:Mopenssl3*}
BROKEN=	fails to build with openssl 3 and later
.endif

post-patch:
	@${REINPLACE_CMD} 's|  dl|  $${CMAKE_DL_LIBS}| ; s|-ldl|$${CMAKE_DL_LIBS}|' ${WRKSRC}/src/*.cmake ${WRKSRC}/src/*/CMakeLists.txt
	@${REINPLACE_CMD} 's|CMAKE_INSTALL_MANDIR "man"|CMAKE_INSTALL_MANDIR "share/man"|' ${WRKSRC}/cmake/XRootDOSDefs.cmake

.include <bsd.port.post.mk>
