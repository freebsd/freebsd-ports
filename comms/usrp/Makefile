# $FreeBSD$

PORTNAME=	usrp
PORTVERSION=	3.4.3
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adrian
DISTNAME=	Ettus-USRP-3.4.3

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Ettus Research USRP driver framework

LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs
BUILD_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs \
		cheetah-analyze:${PORTSDIR}/devel/py-cheetah \
		rst2html:${PORTSDIR}/textproc/py-docutils \
		orcc:${PORTSDIR}/devel/orc \
		sdcc:${PORTSDIR}/lang/sdcc

USES=			compiler:c++0x cmake:outsource gmake pkgconfig dos2unix
COMPILER_FEATURES=	libc++
USE_LDCONFIG=		yes
CMAKE_SOURCE_PATH=	${WRKSRC}/host
MAKE_JOBS_UNSAFE=	yes

# for excruciating debug use this -db
#CMAKE_ARGS+=	--debug-output --trace
DOCSDIR=	share/doc/uhd
WRKSRC=		${WRKDIR}/EttusResearch-UHD-Mirror-6047010

OPTIONS_DEFINE=		USRP1 USRP2 DOCS
OPTIONS_DEFAULT=	USRP1 USRP2
USRP1_DESC=	Build Ettus USRP1 firmware
USRP2_DESC=	Build Ettus USRP2 firmware

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=	needs libusb 1.0
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
CMAKE_ARGS+=	-DENABLE_DOXYGEN:STRING="ON"
HAVEDOCS=	YES
.endif

.if ${PORT_OPTIONS:MUSRP1}
BUILD_DEPENDS+=	sdcc:${PORTSDIR}/lang/sdcc
USRP1=	YES
PLIST_SUB+=	PUSRP1=""
.else
PLIST_SUB+=	PUSRP1="@comment "
.endif

.if ${PORT_OPTIONS:MUSRP2}
BUILD_DEPENDS+=	${LOCALBASE}/zpu/bin/zpu-elf-gcc:${PORTSDIR}/devel/zpu-gcc \
		${LOCALBASE}/zpu/bin/zpu-elf-as:${PORTSDIR}/devel/zpu-binutils
USRP2=	YES
PLIST_SUB+=	PUSRP2=""
.else
PLIST_SUB+=	PUSRP2="@comment "
.endif

CONFIGURE_WRKSRC=	${WRKSRC}/host
CMAKE_SOURCE_PATH=	${WRKSRC}/host

# usrp1 and usrp2 should be ports of their own

post-build:
# build usrp firmware
	(export PATH=${LOCALBASE}/zpu/bin:${PATH};\
	cd ${WRKSRC}/images && ${GMAKE} -f Makefile images)

.if	USRP1
	(cd ${WRKSRC}/images && ${GMAKE} -f Makefile images_usrp1)
.endif
.if	USRP2
#firmware/fx2/build
	(export PATH=${LOCALBASE}/zpu/bin:${PATH};\
	cd ${WRKSRC}/images && ${GMAKE} -f Makefile images_usrp2)
.endif

do-install:
# install host component
# hack the install prefix now
	@${REINPLACE_CMD} -e "s|/usr/local|${STAGEDIR}${PREFIX}|g" \
		${CONFIGURE_WRKSRC}/cmake_install.cmake
	cd ${CONFIGURE_WRKSRC} && ${MAKE} install
# install usrp firmware
	${MKDIR} ${STAGEDIR}${PREFIX}/share/uhd
	${MKDIR} ${STAGEDIR}${PREFIX}/share/uhd/images
.if USRP2
.for f in usrp_n200_fw.bin usrp2_fw.bin \
		usrp_n210_fw.bin
	${INSTALL_DATA} ${WRKSRC}/images/images/${f} ${STAGEDIR}${PREFIX}/share/uhd/images/$f
.endfor
.endif
.if USRP1
.for f in usrp1_fw.ihx usrp1_fpga.rbf usrp1_fpga_4rx.rbf usrp_b100_fw.ihx
	${INSTALL_DATA} ${WRKSRC}/images/images/${f} ${STAGEDIR}${PREFIX}/share/uhd/images/$f
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/uhd/fpga/usrp1/rev2
	${INSTALL_DATA}	${WRKSRC}/fpga/usrp1/rbf/rev2/*.rbf \
		${STAGEDIR}${PREFIX}/share/uhd/fpga/usrp1/rev2
	${MKDIR} ${STAGEDIR}${PREFIX}/share/uhd/fpga/usrp1/rev4
	${INSTALL_DATA}	${WRKSRC}/fpga/usrp1/rbf/rev4/*.rbf \
		${STAGEDIR}${PREFIX}/share/uhd/fpga/usrp1/rev4
.endif

.include <bsd.port.post.mk>
