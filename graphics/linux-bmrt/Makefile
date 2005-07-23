# New ports collection makefile for:   linux-bmrt
# Date created:                        4 May 2000
# Whom:                                R Joseph Wright
#
# $FreeBSD$
#

PORTNAME=	bmrt
PORTVERSION=	2.6beta
PORTREVISION=	2
CATEGORIES=	graphics linux
MASTER_SITES=	#fetch manually
PKGNAMEPREFIX=	linux-
DISTNAME=	BMRT${PORTVERSION}.linux-glibc2

MAINTAINER=	rjoseph@mammalia.org
COMMENT=	A collection of rendering programs that use the RenderMan interface

.ifdef WITH_NVIDIA_GL
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif

WRKSRC=		${WRKDIR}/BMRT2.6
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
NO_CDROM=	"See the License"
USE_LINUX=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		may not be automatically fetched due to licensing \
		restrictions.  You must manually fetch the Linux version at \
		http://www.exluna.com/bmrt/download/index.html. \
		Once you have read and agreed to the license and \
		${DISTFILES} has been downloaded, move it to \
		${DISTDIR} and then restart this build.
.endif

INC_DIR=	${PREFIX}/include/bmrt
LIB_DIR=	${PREFIX}/lib/bmrt
DOC_DIR=	${PREFIX}/share/doc/bmrt
PROGRAM=	composite iv mkmip mkmosaic rendrib rgl slc slctell
SCRIPT=		farm frankenrender

pre-install:
	${MV} ${WRKSRC}/bin/frankenrender ${WRKSRC}/bin/frankenrender.old
	${SED} 's/\/usr\/local\/bin\/perl/\/usr\/bin\/perl/' ${WRKSRC}/bin/frankenrender.old > ${WRKSRC}/bin/frankenrender

do-install:
	${MKDIR} ${LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/lib/bmrt
	${MKDIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bmrtdoc.pdf ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/License ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOC_DIR}
	${MKDIR} ${DOC_DIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOC_DIR}/html
	${MKDIR} ${INC_DIR}
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/bmrt
	${MKDIR} ${PREFIX}/share/examples/bmrt
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/bmrt
	${MKDIR} ${PREFIX}/share/bmrt ${PREFIX}/share/bmrt/shaders
	${INSTALL_DATA} ${WRKSRC}/.rendribrc ${PREFIX}/share/bmrt/rendribrc.sample
	${INSTALL_DATA} ${WRKSRC}/shaders/* ${PREFIX}/share/bmrt/shaders
.for i in ${SCRIPT}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${i} ${PREFIX}/bin
.endfor
.for i in ${PROGRAM}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${i} ${PREFIX}/bin
	${BRANDELF} -t Linux ${PREFIX}/bin/${i}
.endfor

post-install:
	@${ECHO} "";
	@${ECHO} "************************************************************************";
	@${ECHO} "";
	@${ECHO} "      Before using these programs, add the following";
	@${ECHO} "      path to your shell environment:";
	@${ECHO} "";
	@${ECHO} "      If using sh (or derivative),";
	@${ECHO} "      export SHADERS=.:${PREFIX}/share/bmrt/shaders";
	@${ECHO} "";
	@${ECHO} "      If using csh (or derivative),";
	@${ECHO} "      setenv .:${PREFIX}/share/bmrt/shaders";
	@${ECHO} "";
	@${ECHO} "      Also, copy ${PREFIX}/share/examples/bmrt/rendribrc.sample";
	@${ECHO} "      to your home directory as .rendribrc, where it may be modified.";
	@${ECHO} "";
	@${ECHO} "************************************************************************";
	@${ECHO} "";

.include <bsd.port.post.mk>
