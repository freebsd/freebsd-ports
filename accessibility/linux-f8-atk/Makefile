# New ports collection makefile for:	linux-atk
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	atk
PORTVERSION=	1.2.0
PORTREVISION=	0
CATEGORIES=	accessibility

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Accessibility Toolkit, Linux/i386 binary

BUILD_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

BASEVERSION=	9
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
RESTRICTED=	"binary under GNU LGPL without accompanying source"
RPM_SET=	atk-1.2.0-2.i386.rpm

pre-install:
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio.pl < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | cpio -id; \
		${FIND} * -type f -o -type l > ${PLIST}
	${ECHO_CMD} @dirrm usr/share/doc/atk-1.2.0 >> ${PLIST}

.include "../../x11-toolkits/linux-gtk/Makefile"
