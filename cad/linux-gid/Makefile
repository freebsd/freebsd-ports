# New ports collection makefile for:	GiD
# Date created:		19 Feb 2004
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	gid
PORTVERSION=	7.4.9b
CATEGORIES=	cad linux
MASTER_SITES=	ftp://gid.cimne.upc.es/pub/gid_adds/Linux/Old/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical pre- and post-processor for numerical simulation programs

RUN_DEPENDS=	${LINUXBASE}${X11BASE}/lib/libX11.so.6:${PORTSDIR}/x11/linux-XFree86-libs

CONFLICTS=	id-utils-[0-9]* coreutils-[0-9]*
ONLY_FOR_ARCHS=	amd64 i386

USE_LINUX?=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

INFO=		gid gid-faq gid-ptype
GID_BINS=	gen2dNNN gid.exe mesh3d99
GID_DATA=	GidPassword.txt License.htm License.txt README.txt
GID_DIRS=	bitmaps problemtypes scripts symbols templates info

post-extract:
	@${REINPLACE_CMD} -e 's+/usr/bin/X11+${X11BASE}/bin+g;'	\
		${WRKDIR}/install
	${RM} ${WRKDIR}/info/gid.info.cvs

do-install:
	@${MKDIR} ${DATADIR}
.for d in ${GID_DATA}
	${INSTALL_DATA} ${WRKDIR}/${d} ${DATADIR}
.endfor
.for d in ${GID_DIRS}
	@${MKDIR} ${DATADIR}/${d}
	@${TAR} -C ${WRKDIR}/${d} -cf - . |	\
	  ${TAR} -C ${DATADIR}/${d} -xf -
	@${CHOWN} -R root:wheel ${DATADIR}/${d}
	@${FIND} ${DATADIR}/${d} -type d -exec ${CHMOD} 0555 {} \;
	@${FIND} ${DATADIR}/${d} -type f -exec ${CHMOD} 0444 {} \;
.endfor
	${RM} ${DATADIR}/info/*.info*
.for b in ${GID_BINS}
	${INSTALL_PROGRAM} ${WRKDIR}/${b} ${DATADIR}
	@${BRANDELF} -t Linux ${DATADIR}/${b}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/install ${DATADIR}
	@(cd ${WRKDIR}; ./install ${DATADIR})
	@${LN} -sf ${DATADIR}/gid ${PREFIX}/bin/gid

.if !defined(NOPORTDOCS)
	for f in ${WRKDIR}/info/gid*.info*; do \
	  ${INSTALL_DATA} $$f ${PREFIX}/info; \
	done
	for f in faq.info ptype.info; do \
	  ${INSTALL_DATA} ${WRKDIR}/info/$$f ${PREFIX}/info/gid-$$f; \
	done
.endif
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKDIR}/Examples -cf - . |	\
	  ${TAR} -C ${EXAMPLESDIR} -xf -
	@${CHOWN} -R root:wheel ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} -type d -exec ${CHMOD} 0555 {} \;
	@${FIND} ${EXAMPLESDIR} -type f -exec ${CHMOD} 0444 {} \;

.include <bsd.port.mk>
