# New ports collection makefile for:   linux-bmrt
# Date created:                        4 May 2000
# Whom:                                R Joseph Wright
#
# $FreeBSD$
#

PORTNAME=	linux-bmrt
PORTVERSION=	2.5
CATEGORIES=	graphics linux
MASTER_SITES=	http://www.bmrt.org/BMRTdownload/
DISTNAME=	BMRT2.5g.linux-glibc2

MAINTAINER=	rjoseph@mammalia.org

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

WRKSRC=		${WRKDIR}/BMRT2.5
NO_BUILD=	yes
NO_CDROM=	"See the License"

DOC_DIR=	${PREFIX}/share/doc/bmrt
FETCH_CMD=	/usr/bin/fetch -Ab
PROGRAM=	composite mkmip mkmosaic rendrib rgl slc slctell
SCRIPT=		farm frankenrender

pre-install:
	${MV} ${WRKSRC}/bin/frankenrender ${WRKSRC}/bin/frankenrender.old
	${SED} 's/\/usr\/local\/bin\/perl/\/usr\/bin\/perl/' ${WRKSRC}/bin/frankenrender.old > ${WRKSRC}/bin/frankenrender

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/lib
	${MKDIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bmrtdoc.pdf ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/License ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOC_DIR}
	${MKDIR} ${DOC_DIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOC_DIR}/html
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include
	${MKDIR} ${PREFIX}/share/examples/bmrt
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/bmrt
	${MKDIR} ${PREFIX}/share/bmrt ${PREFIX}/share/bmrt/shaders
	${INSTALL_DATA} ${WRKSRC}/.rendribrc ${PREFIX}/share/bmrt
	${INSTALL_DATA} ${WRKSRC}/shaders/* ${PREFIX}/share/bmrt/shaders
.for i in ${SCRIPT}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${i} ${PREFIX}/bin
.endfor
.for i in ${PROGRAM}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${i} ${PREFIX}/bin
	/usr/bin/brandelf -t Linux ${PREFIX}/bin/${i}
.endfor

post-install:
	@${ECHO} "";
	@${ECHO} "************************************************************************";
	@${ECHO} "";
	@${ECHO} "      This is shareware that is free for non-commercial use.";
	@${ECHO} "      Please read ${PREFIX}/share/doc/bmrt/License before proceeding.";
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
	@${ECHO} "      Also, copy ${PREFIX}/share/examples/bmrt/.rendribrc";
	@${ECHO} "      to your home directory, where it may be modified.";
	@${ECHO} "";
	@${ECHO} "************************************************************************";
	@${ECHO} "";

.include <bsd.port.mk>
