# $FreeBSD$

PORTNAME=	splat
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.qsl.net/kd2bd/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Used in calculating path losses, useful to ham radio and others

LICENSE=	GPLv2

USES=		tar:bzip2

PORTDOCS=	README README2 CHANGES

OPTIONS_DEFINE=	DOCS HRM
OPTIONS_SINGLE=	SRM HRM
OPTIONS_SINGLE_SRM=	SRM_2X2 SRM_3X3 SRM_4X4 SRM_5X5 SRM_6X6 SRM_7X7 SRM_8X8
OPTIONS_SINGLE_HRM=	HRM_1X1 HRM_2X2 HRM_3X3 HRM_4X4 HRM_5X5 HRM_6X6 HRM_7X7 HRM_8X8
OPTIONS_DEFAULT=	SRM_4X4 HRM_4X4

SRM_2X2_DESC=	2 x 2 degrees
SRM_3X3_DESC=	3 x 3 degrees
SRM_4X4_DESC=	4 x 4 degrees
SRM_5X5_DESC=	5 x 5 degrees
SRM_6X6_DESC=	6 X 6 degrees
SRM_7X7_DESC=	7 x 7 degrees
SRM_8X8_DESC=	8 x 8 degrees

HRM_DESC=	Optionally build High Resolution splat-hd
HRM_1X1_DESC=	1 x 1 degrees
HRM_2X2_DESC=	2 x 2 degrees
HRM_3X3_DESC=	3 x 3 degrees
HRM_4X4_DESC=	4 x 4 degrees
HRM_5X5_DESC=	5 x 5 degrees
HRM_6X6_DESC=	6 X 6 degrees (For 64 bit systems)
HRM_7X7_DESC=	7 x 7 degrees (For 64 bit systems)
HRM_8X8_DESC=	8 x 8 degrees (For 64 bit systems)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHRM}
PLIST_FILES+=	bin/splat-hd
PLIST_FILES+=	bin/srtm2sdf-hd
.endif

do-build:
	@${ECHO_CMD}	"#define HD_MODE	 0"	> ${WRKSRC}/splat.h
.if ${PORT_OPTIONS:MSRM_2X2}
	@${ECHO_CMD}	"#define MAXPAGES 4"	>> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MSRM_3X3}
	@${ECHO_CMD}	"#define MAXPAGES 9"	>> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MSRM_4X4}
	@${ECHO_CMD}	"#define MAXPAGES 16"	>> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MSRM_5X5}
	@${ECHO_CMD}	"#define MAXPAGES 25"	>> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MSRM_6X6}
	@${ECHO_CMD}	"#define MAXPAGES 36"	>> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MSRM_7X7}
	@${ECHO_CMD}	"#define MAXPAGES 49"	>> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MSRM_8X8}
	@${ECHO_CMD}	"#define MAXPAGES 64"	>> ${WRKSRC}/splat.h
.endif
.if defined(PACKAGE_BUILDING) || defined(BATCH)
	@${ECHO_CMD}	"#define HD_MODE	 0"	> ${WRKSRC}/splat.h
	@${ECHO_CMD}	"#define MAXPAGES 16"	>> ${WRKSRC}/splat.h
.endif
	cd ${WRKSRC} && \
		${CXX} ${CXXFLAGS} -fPIC -lm -lbz2 -o splat itwom3.0.cpp splat.cpp

.if ${PORT_OPTIONS:MHRM}
	@${ECHO_CMD}	"Building HD"
	@${RM}		${WRKSRC}/splat.h
	@${ECHO_CMD}	"#define HD_MODE	 1"	> ${WRKSRC}/splat.h
.if ${PORT_OPTIONS:MHRM_1X1}
	@${ECHO_CMD}	"#define MAXPAGES 1"	>> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MHRM_2X2}
	@${ECHO_CMD}	"#define MAXPAGES 4"	>> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MHRM_3X3}
	@${ECHO_CMD}	"#define MAXPAGES 9"	>> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MHRM_4X4}
	@${ECHO_CMD}	"#define MAXPAGES 16"	>> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MHRM_5X5}
	@${ECHO_CMD}	"#define MAXPAGES 25"	>> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MHRM_6X6}
	@${ECHO_CMD}	"#define MAXPAGES 36"	>> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MHRM_7X7}
	@${ECHO_CMD}    "#define MAXPAGES 49"   >> ${WRKSRC}/splat.h
.endif
.if ${PORT_OPTIONS:MHRM_8X8}
	@${ECHO_CMD}    "#define MAXPAGES 64"   >> ${WRKSRC}/splat.h
.endif

	cd ${WRKSRC} && \
		${CXX} ${CXXFLAGS} -mcmodel=medium -lm -lbz2 -o splat-hd itwom3.0.cpp splat.cpp
.endif
	cd ${WRKSRC}/utils && \
		${CC} ${CFLAGS} -o citydecoder citydecoder.c && \
		${CC} ${CFLAGS} -o usgs2sdf usgs2sdf.c && \
		${CC} ${CFLAGS} -lbz2 -o srtm2sdf srtm2sdf.c && \
		${CC} ${CFLAGS} -lz -o fontdata fontdata.c && \
		${CC} ${CFLAGS} -lz -lm -o bearing bearing.c

do-install:
.for f in splat utils/citydecoder utils/usgs2sdf utils/srtm2sdf \
	utils/fontdata utils/bearing
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/utils/postdownload ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/english/man/splat.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.if ${PORT_OPTIONS:MHRM}
	${INSTALL_PROGRAM} ${WRKSRC}/splat-hd ${STAGEDIR}${PREFIX}/bin
	${LN} -s srtm2sdf ${STAGEDIR}${PREFIX}/bin/srtm2sdf-hd
.endif

.include <bsd.port.mk>
