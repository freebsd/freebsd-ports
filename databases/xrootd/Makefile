# $FreeBSD$

PORTNAME=	xrootd
DISTVERSION=	4.8.5
CATEGORIES=	databases
MASTER_SITES=	http://xrootd.org/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	767d9770b01a89125b45fbea417364eb9efee528.patch:-p1 \
		0a2240ed70edc769891cb5155aeb99405ceeb7f4.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for fast, low latency, scalable data access

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	librados.so:net/ceph

USES=		cmake:outsource gnome localbase:ldflags pkgconfig readline shebangfix ssl
SHEBANG_GLOB=	*.sh
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR:STRING=${PREFIX}/lib \
		-DCMAKE_INSTALL_BINDIR:STRING=${PREFIX}/bin \
		-DCMAKE_INSTALL_INCLUDEDIR:STRING=${PREFIX}/include \
		-DCMAKE_INSTALL_MANDIR:STRING=${PREFIX}/man \
		-DCMAKE_INSTALL_DATADIR:STRING=${DATADIR}

CXXFLAGS+=	-Ddirent64=dirent
LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=	KERBEROS5
OPTIONS_SUB=	yes

KERBEROS5_CMAKE_BOOL=	ENABLE_KRB5
KERBEROS5_BROKEN=	build picks base kerberos, but needs the port one (problem only exists in poudriere builds for some reason)
KERBEROS5_LIB_DEPENDS=	libkrb5.so:security/krb5

post-patch:
	@${REINPLACE_CMD} 's|  dl|  $${CMAKE_DL_LIBS}| ; s|-ldl|$${CMAKE_DL_LIBS}|' ${WRKSRC}/src/*.cmake ${WRKSRC}/src/*/CMakeLists.txt

.include <bsd.port.mk>
