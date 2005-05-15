# New ports collection makefile for:	ut2004-demo
# Date created:			31 Mar 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		ut2004-demo
PORTVERSION=		3334
CATEGORIES=		games linux
MASTER_SITES=		${MASTER_SITE_GENTOO} \
			http://ftp.games.skynet.be/pub/misc/
MASTER_SITE_SUBDIR=	distfiles		# for MASTER_SITE_GENTOO
PKGNAMEPREFIX=		linux-
DISTNAME=		ut2004-lnx-demo${PORTVERSION}
EXTRACT_SUFX=		.run

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		Unreal Tournament 2004 demo

RUN_DEPENDS=		${LINUXBASE}/usr/X11R6/lib/libX11.so.6:${PORTSDIR}/x11/linux-XFree86-libs

ONLY_FOR_ARCHS=		i386
PREFIX?=		${X11BASE}	# USE_X_PREFIX would pull in USE_XLIB
USE_LINUX=		yes
NO_PACKAGE=		Distfile is 275MB, set FORCE_PACKAGE if you really want to build this package
RESTRICTED=		Redistribution is limited, see license
NO_BUILD=		yes
NO_WRKSUBDIR=		yes
UTDIR=			${PREFIX}/lib/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} -c +8664 ${_DISTDIR}/${DISTFILES} | ${TAR} zxf -
.for f in linux-x86.tar.bz2 ut2004demo.tar.bz2
	@cd ${WRKSRC} && ${TAR} yxf ${f}
.endfor
	@cd ${WRKSRC} && ${TAR} zxf setupstuff.tar.gz

post-patch:
	@${SED} -e 's|@UTDIR@|${UTDIR}|' ${FILESDIR}/ut2004-demo.in \
		> ${WRKSRC}/ut2004-demo

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ut2004-demo ${PREFIX}/bin

	${MKDIR} ${UTDIR}
.for d in Animations Benchmark ForceFeedback KarmaData Maps Music Sounds \
	Speech StaticMeshes System Textures Web
	${CP} -R ${WRKSRC}/${d} ${UTDIR}
.endfor

	-${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${UTDIR}/*
	${FIND} ${UTDIR}/* -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	${FIND} ${UTDIR}/* -type d -exec ${CHMOD} ${BINMODE} {} \;

.for f in libSDL-1.2.so.0 openal.so
	-${CHOWN} ${LIBOWN}:${LIBGRP} ${UTDIR}/System/${f}
	${CHMOD} ${LIBMODE} ${UTDIR}/System/${f}
.endfor

.for f in ucc-bin ut2004-bin
	-${CHOWN} ${BINOWN}:${BINGRP} ${UTDIR}/System/${f}
	${CHMOD} ${BINMODE} ${UTDIR}/System/${f}
.endfor

	${MKDIR} ${DATADIR}
.for f in Help/UT2004Logo.bmp ut2004.xpm
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in Help/Manual.pdf README.linux
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
