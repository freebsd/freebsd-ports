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

MAINTAINER=	wjv@FreeBSD.org

# It doesn't seem possible to construct a LIB_DEPENDS for Allegro(?)
# The dependence on the version number is also sub-optimal.
BUILD_DEPENDS=	allegro-config:${PORTSDIR}/devel/allegro
RUN_DEPENDS=	allegro-config:${PORTSDIR}/devel/allegro

NO_CDROM=	Reverse-engineered version of copyrighted abandonware
NO_PACKAGE=	${NO_CDROM}
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-oq
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=
SHAREDIR=	${PREFIX}/share/${PORTNAME}

# Currently, everything required to run newkind (including the binary) is
# installed to ${SHAREDIR}.  A shell script wrapper is then installed to
# ${PREFIX}/bin.  A more elegant installation to the standard directory
# hierarchy under ${PREFIX} would require extensive patching of source files,
# which will have to be maintained across future versions.  If anyone feels
# up to it, you're more than welcome...  :-)
do-install:
	@ ${MKDIR} ${SHAREDIR}/data
	@ ${INSTALL_PROGRAM} ${WRKSRC}/newkind.exe ${SHAREDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/elite.dat ${WRKSRC}/*.cfg \
	  ${WRKSRC}/*.bmp ${WRKSRC}/*.wav ${SHAREDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/data/* ${SHAREDIR}/data
	@ ${MKDIR} ${PREFIX}/bin
	@ ${ECHO} "#!${SH}" > ${WRKSRC}/newkind
	@ ${ECHO} "cd ${SHAREDIR} && exec \"./newkind.exe\" \"\$$@\"" \
	  >> ${WRKSRC}/newkind
	@ ${INSTALL_SCRIPT} ${WRKSRC}/newkind ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
