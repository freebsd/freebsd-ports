# New ports collection makefile for:	omniORB
# Date created:		14 May 1997
# Whom:			ejc@bazzle.com
#
# $FreeBSD$
#

PORTNAME=	omniORB
PORTVERSION=	3.0.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.orl.co.uk/pub/omniORB/omniORB3/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//g}

MAINTAINER=	ejc@bazzle.com

MAN1=		catior.1 genior.1 nameclt.1 obuildtree.1 ols.1 omake.1 \
		omniNames.1 opriv.1 oshadow.1

WRKSRC=		${WRKDIR}/omni/src

BUILD_DEPENDS=  python1.5:${PORTSDIR}/lang/python15
RUN_DEPENDS=    python1.5:${PORTSDIR}/lang/python15

USE_PYTHON=	yes
USE_NEWGCC=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	export
MAKE_ENV+=	CDEBUGFLAGS="${CFLAGS}" CXXDEBUGFLAGS="${CXXFLAGS}" \
		BSD_INSTALL="${INSTALL}" PYTHON_CMD="${PYTHON_CMD}" \
		MKDIR="${MKDIR}"
ONLY_FOR_ARCHS=	i386

# Setting ${CONFIG_TARGET} to this value  and patching it into
# ${WRKSRC}/../config/config.mk via the post-patch target ensures that the
# internal make variable __OSVERSION__ is set to 4.  This activates gcc
# 2.9.5-specific code, and obviates the need for most of the patches
# previously required since there are now version checks in the source.
CONFIG_TARGET=	x86_freebsd_4.0

post-patch:
	@${SETENV} LANG=C ${PERL} -pi -e 's/__PLATFORM__/${CONFIG_TARGET}/;' \
		${WRKSRC}/../config/config.mk

binfiles=	catior convertior genior nameclt omkdepend omniMapper \
		omniNames
scriptfiles=	omniidl omniidlrun.py

do-install:
.for binfile in ${binfiles}
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/${CONFIG_TARGET}/${binfile} \
		${PREFIX}/bin
.endfor
.for scriptfile in ${scriptfiles}
	${INSTALL_SCRIPT} ${WRKSRC}/../bin/${CONFIG_TARGET}/${scriptfile} \
		${PREFIX}/bin
.endfor
	cd ${WRKSRC}/../lib/${CONFIG_TARGET} && \
		find . |cpio -pdum -R ${BINOWN}:${BINGRP} ${PREFIX}/lib
.for m in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/../man/man1/${m} ${PREFIX}/man/man1
.endfor
	${MKDIR} ${PREFIX}/include/omniORB3
	${MKDIR} ${PREFIX}/include/omnithread
	${INSTALL_DATA} ${WRKSRC}/../include/omnithread.h ${PREFIX}/include
	cd ${WRKSRC}/../include && \
		${INSTALL_DATA} omnithread/* ${PREFIX}/include/omnithread; \
		${INSTALL_DATA} omniORB3/* ${PREFIX}/include/omniORB3
	@ cd ${.CURDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/omniORB
	${INSTALL_DATA} ${WRKSRC}/../README.unix ${PREFIX}/share/doc/omniORB
	${INSTALL_DATA} ${WRKSRC}/../README.FreeBSD ${PREFIX}/share/doc/omniORB
	${INSTALL_DATA} ${WRKSRC}/../ReleaseNote_omniORB_301 ${PREFIX}/share/doc/omniORB
	cd ${WRKSRC}/../doc && \
		find . |cpio -pdum -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/omniORB
.endif

.include <bsd.port.mk>
