# New ports collection makefile for:	jfduke3d
# Date Created:				26 August 2005
# Whom:					<arundel@h3c.de>
#
# $FreeBSD$

PORTNAME=	jfduke3d
PORTVERSION=	20050531
CATEGORIES=	games
MASTER_SITES=	ftp://dialup.edgefiles.com/edgenetwork.org/jonof/buildport/ \
		ftp://ftp1.edgefiles.com/edgenetwork.org/jonof/buildport/ \
		ftp://ftp2.edgefiles.com/edgenetwork.org/jonof/buildport/ \
		http://members.iinet.net.au.nyud.net:8090/~jonof/
DISTFILES=	${PORTNAME}_src_${PORTVERSION}.zip \
		jfbuild_src_${PORTVERSION}.zip

MAINTAINER=	arundel@h3c.de
COMMENT=	Jonathon Fowler's Duke Nukem 3D Port

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_ZIP=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GNOME=	gtk20
CONFLICTS=	duke3d-200[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}_src_${PORTVERSION}

PROG_FILES=	${WRKSRC}/duke3d ${WRKSRC}/build
DATA_FILES=	${WRKSRC}/build.cfg
SCRIPT_FILES=	${WRKDIR}/fix.sh ${WRKDIR}/duke3d.sh ${WRKDIR}/build.sh
PORTDOCS=	ChangeLog readme.txt releasenotes.html duke3d.def.sample GNU.TXT

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not build on !i386 (hardcodes i386-specific compiler flags)"
.endif

pre-build:
		@${REINPLACE_CMD} -e 's|EROOT=../build/|EROOT=../jfbuild_src_${PORTVERSION}/|g' \
			${WRKSRC}/Makefile

pre-install:
		@${SED} -e 's|%%DUKEDIR%%|${DATADIR}|g' ${FILESDIR}/fix.sh > \
			${WRKDIR}/fix.sh
		@${SED} -e 's|%%DUKEDIR%%|${DATADIR}|g' ${FILESDIR}/wrapper.sh > \
			${WRKDIR}/duke3d.sh
		@${SED} -e 's|%%DUKEDIR%%|${DATADIR}|g' ${FILESDIR}/build-wrapper.sh > \
			${WRKDIR}/build.sh

do-install:
		${INSTALL} -d ${DATADIR}
		${INSTALL_PROGRAM} ${PROG_FILES} ${DATADIR}
		${INSTALL_DATA} ${DATA_FILES} ${DATADIR}
		${INSTALL_SCRIPT} ${SCRIPT_FILES} ${DATADIR}
		${LN} -fs ${DATADIR}/duke3d.sh ${PREFIX}/bin/duke3d
		${LN} -fs ${DATADIR}/build.sh ${PREFIX}/bin/duke3d-build

post-install:
.ifndef(NOPORTDOCS)
		${INSTALL} -d ${DOCSDIR}

.for file in ${PORTDOCS}
		${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
		${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
