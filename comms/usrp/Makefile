# $FreeBSD$

PORTNAME=	usrp
PORTVERSION=	3.4.3
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adrian
DISTNAME=	Ettus-USRP-3.4.3

MAINTAINER=	adrian@FreeBSD.org
COMMENT=	Ettus Research USRP driver framework

LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs
BUILD_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs \
		cheetah-analyze:${PORTSDIR}/devel/py-cheetah \
		rst2html:${PORTSDIR}/textproc/py-docutils \
		orcc:${PORTSDIR}/devel/orc \
		sdcc:${PORTSDIR}/lang/sdcc

USE_DOS2UNIX=		yes
USES=			cmake:outsource gmake pkgconfig
USE_LDCONFIG=		yes
CMAKE_SOURCE_PATH=	${WRKSRC}/host

# for excruciating debug use this -db
CMAKE_ARGS=	--debug-output --trace
DOCSDIR=	share/doc/uhd
WRKSRC=		${WRKDIR}/EttusResearch-UHD-Mirror-6047010

OPTIONS_DEFINE=		USRP1 USRP2
OPTIONS_DEFAULT=	USRP1 USRP2
USRP1_DESC=	Build Ettus USRP1 firmware
USRP2_DESC=	Build Ettus USRP2 firmware

NO_STAGE=	yes
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

do-build:
# build host component
	(export PATH=${LOCALBASE}/zpu/bin:${PATH};cd ${CONFIGURE_WRKSRC}&&${GMAKE})
# build usrp firmware
#	(export PATH=${LOCALBASE}/zpu/bin:${PATH};\
#	cd ${WRKSRC}/images && ${GMAKE} -f Makefile images)

.if	USRP1
	(cd ${WRKSRC}/images && ${GMAKE} -f Makefile images_usrp1)
.endif
.if	USRP2
	(export PATH=${LOCALBASE}/zpu/bin:${PATH};\
	cd ${WRKSRC}/images && ${GMAKE} -f Makefile images_usrp2)
.endif

do-install:
# install host component
	cd ${CONFIGURE_WRKSRC} && ${MAKE} install
# install usrp firmware
	${MKDIR} ${PREFIX}/share/uhd
	${MKDIR} ${PREFIX}/share/uhd/images

.if USRP2
.for f in usrp_n200_fw.bin usrp2_fw.bin \
		usrp_n210_fw.bin
	${INSTALL_DATA} ${WRKSRC}/images/images/${f} ${PREFIX}/share/uhd/images/$f
.endfor
.endif

.if USRP1
.for f in usrp1_fw.ihx usrp1_fpga.rbf usrp1_fpga_4rx.rbf usrp_b100_fw.ihx
	${INSTALL_DATA} ${WRKSRC}/images/images/${f} ${PREFIX}/share/uhd/images/$f
.endfor
	${MKDIR} ${PREFIX}/share/uhd/fpga/usrp1/rev2
	${INSTALL_DATA}	${WRKSRC}/fpga/usrp1/rbf/rev2/*.rbf \
		${PREFIX}/share/uhd/fpga/usrp1/rev2
	${MKDIR} ${PREFIX}/share/uhd/fpga/usrp1/rev4
	${INSTALL_DATA}	${WRKSRC}/fpga/usrp1/rbf/rev4/*.rbf \
		${PREFIX}/share/uhd/fpga/usrp1/rev4
.endif

post-install:
	${ECHO_MSG} fpga and firmware installed in /usr/local/share/uhd
.if HAVEDOCS
	${ECHO_MSG} docs installed in /usr/local/share/doc/uhd
.endif

.include <bsd.port.post.mk>
