# $FreeBSD$

MASTER_SITES=	http://www.openscenegraph.org/downloads/snapshots/
DISTNAME=	OSG_OP_OT-1.2

MD5_FILE=	${.CURDIR}/../../graphics/osg/distinfo
USE_ZIP=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAKEFILE=	GNUmakefile
MAKE_ARGS=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		CXX="${CXX}" \
		INST_LOCATION="${PREFIX}" \
		INST_EXAMPLES="${EXAMPLESDIR}/bin" \
		INST_SRC="${EXAMPLESDIR}/src" \
		INST_EXAMPLE_SRC="${EXAMPLESDIR}/src" \
		INSTBINCMD="${INSTALL_PROGRAM}" \
		INSTXCMD="${INSTALL_PROGRAM}" \
		INSTDEVCMD="${INSTALL_DATA}" \
		INSTRCMD="${INSTALL_DATA}"
ALL_TARGET=	opt

post-patch: osg-post-patch

osg-post-patch:
	@${REINPLACE_CMD} -Ee 's|-O2|${CXXFLAGS}|; \
		s|(-I\|-L\|-rpath )/usr/local|\1${LOCALBASE}|; \
		s|(-I\|-L\|-rpath )/usr/X11R6|\1${X11BASE}|' \
		${WRKSRC}/Make/makedefs
	@${REINPLACE_CMD} -e 's|DOF=$$(OPTF)|DOF="$$(OPTF)"|' \
		${WRKSRC}/Make/makerules
