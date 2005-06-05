# New ports collection makefile for:	acroread
# Date created:		4 June 2005
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	acroread
PORTVERSION=	7.0.0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/reader/unix/7x/7.0/jpn/
DISTNAME=	AdbeRdr70_linux_jpn
DIST_SUBDIR=	acroread

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Adobe Reader which allows view, print, and search PDF documents

BUILD_DEPENDS=	${LOCALBASE}/bin/jless:${PORTSDIR}/japanese/less
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
		${LINUXBASE}/usr/lib/libpango-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango \
		${LINUXBASE}/usr/X11R6/lib/libXext.so.6:${PORTSDIR}/x11/linux-XFree86-libs

RESTRICTED=	"Must fill out redistribution form at http://www.adobe.com/products/acrobat/distribute.html"
NO_PACKAGE=	"Use and redistribution with repackaging are not allowed"
IS_INTERACTIVE=	yes
CONFLICTS=	acroread-[0-9]* acroread[57]-[0-9]* \
		ja-acroread5-[0-9]*
ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX?=	yes
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
PLIST_SUB=	ACRODIR=${ACRODIR}
SUB_FILES=	acroread
SUB_LIST=	INSTALLDIR=${INSTALLDIR}
WRKSRC=		${WRKDIR}/AdobeReader

ACRODIR=	Acrobat7
INSTALLDIR=	${PREFIX}/${ACRODIR}
INSTALLEXEC=	${SETENV} UNAME_s=Linux \
			UNAME_r="Linux Compatibility on FreeBSD" \
			InstallDir=${INSTALLDIR} \
			PAGER=jless \
			${SH} ./INSTALL

do-install:
	${MKDIR} ${INSTALLDIR}
	cd ${WRKSRC} && ${INSTALLEXEC}
	# disable the PPKLite plugin as it requires an LDAP share lib
	${CHMOD} 0 ${INSTALLDIR}/Reader/intellinux/plug_ins/PPKLite.api
	${INSTALL_SCRIPT} ${WRKDIR}/acroread ${PREFIX}/bin/acroread

.include <bsd.port.mk>
