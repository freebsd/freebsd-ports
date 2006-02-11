# New ports collection makefile for:	acroread
# Date created:		4 June 2005
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	acroread
PORTVERSION=	7.0.5
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	http://ardownload.adobe.com/pub/adobe/reader/unix/7x/7.0.5/jpn/ \
		ftp://ftp.adobe.com/pub/adobe/reader/unix/7x/7.0.5/jpn/
DISTNAME=	AdobeReader_jpn-7.0.5-1.i386
DIST_SUBDIR=	acroread

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Adobe Reader which allows view, print, and search PDF documents

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
		${LINUXBASE}/usr/lib/libpango-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango

RESTRICTED=	"Must fill out redistribution form at http://www.adobe.com/products/acrobat/distribute.html"
NO_PACKAGE=	"Use and redistribution with repackaging are not allowed"
CONFLICTS=	acroread-[0-9]* acroread[57]-[0-9]* \
		ja-acroread5-[0-9]*
ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
PLIST_SUB=	ACRODIR=${ACRODIR} \
		PLUGINDIR=${PLUGINDIR}
SUB_FILES=	acroread
SUB_LIST=	INSTALLDIR=${INSTALLDIR} \
		LINUXBASE=${LINUXBASE}
WRKSRC=		${WRKDIR}/AdobeReader

ACRODIR=	Acrobat7
PLUGINDIR=	lib/browser_linux_plugins
POSTPROCESS=	${AWK} '/^  if \[ `uname -s` = \"Linux\" \] ; then/ { print "ReadTar=\"\"; SearchTar=\"\"; CustomTar=\"\"; return;" } /^AcroSerNum/ { print "ScriptDirectory=${WRKSRC}" } { print }'
INSTALLDIR=	${PREFIX}/${ACRODIR}
INSTALLEXEC=	${POSTPROCESS} < ./INSTALL | \
			${SETENV} UNAME_s=Linux \
			UNAME_r="Linux Compatibility on FreeBSD" \
			${SH} /dev/stdin --install_path=${INSTALLDIR}

do-install:
	${MKDIR} ${INSTALLDIR}
	cd ${WRKSRC} && ${INSTALLEXEC}
	# disable the PPKLite plugin as it requires an LDAP share lib
	${CHMOD} 0 ${INSTALLDIR}/Reader/intellinux/plug_ins/PPKLite.api
	${INSTALL_SCRIPT} ${WRKDIR}/acroread ${PREFIX}/bin/acroread
	${BRANDELF} -t Linux ${INSTALLDIR}/Reader/intellinux/bin/acroread

post-install:
	${MKDIR} ${PREFIX}/${PLUGINDIR}
	${LN} -s -f \
		${PREFIX}/${ACRODIR}/Browser/intellinux/nppdf.so \
		${PREFIX}/${PLUGINDIR}/nppdf.so

.include <bsd.port.mk>
