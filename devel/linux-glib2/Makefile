# New ports collection makefile for:	linux-glib2
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	glib2
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	devel linux

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Version 2.X Linux/i386 binary port of GLib

BASEVERSION=	9
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
RESTRICTED=	"binary under GNU LGPL without accompanying source"
RPM_SET=	glib2-2.2.1-1.i386.rpm

pre-install:
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | \
		${CPIO} -id; ${FIND} * -type f -o -type l > ${PLIST}; \
		${FIND} -d * -type d | ${GREP} glib | ${SED} -e 's:^:@dirrm :' \
		>> ${PLIST}

.include "../../x11-toolkits/linux-gtk/Makefile"
