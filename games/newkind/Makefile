# New ports collection makefile for:	Elite - The New Kind
# Date created:		23 October 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	newkind
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://home.clara.net/cjpinder/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}${EXTRACT_SUFX} ${PORTNAME}b${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Elite: The New Kind - a remake of the 8-bit classic

LIB_DEPENDS=	alleg.4:${PORTSDIR}/devel/allegro

BROKEN=		Does not build with version of devel/allegro currently in ports
NO_CDROM=	Reverse-engineered version of copyrighted abandonware
NO_PACKAGE=	${NO_CDROM}
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-oq
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=
NK_SCRIPT=	${WRKSRC}/newkind

# Currently, everything required to run newkind (including the binary) is
# installed to ${DATADIR}.  A shell script wrapper is then installed to
# ${PREFIX}/bin.  A more elegant installation to the standard directory
# hierarchy under ${PREFIX} would require extensive patching of source files,
# which will have to be maintained across future versions.  If anyone feels
# up to it, you're more than welcome...  :-)
do-install:
	@ ${MKDIR} ${DATADIR}/data
	@ ${INSTALL_PROGRAM} ${WRKSRC}/newkind.exe ${DATADIR}
	@ ${INSTALL_DATA} ${WRKSRC}/elite.dat ${WRKSRC}/*.cfg \
	  ${WRKSRC}/*.bmp ${WRKSRC}/*.wav ${DATADIR}
	@ ${INSTALL_DATA} ${WRKSRC}/data/* ${DATADIR}/data
	@ ${MKDIR} ${PREFIX}/bin
	@ ${ECHO_CMD} "#!${SH}" > ${NK_SCRIPT}
	@ ${ECHO_CMD} "cd ${DATADIR} && exec \"./newkind.exe\" \"\$$@\"" \
	  >> ${NK_SCRIPT}
	@ ${INSTALL_SCRIPT} ${NK_SCRIPT} ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
