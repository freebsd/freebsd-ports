# New ports collection makefile for:	linux-ttfonts-ja
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		ttfonts-ja
PORTVERSION=		1.2
CATEGORIES=		japanese x11-fonts linux

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Japanese Truetype fonts for use with Linux emulation

BASEVERSION=	9
MD5_FILE=	${MASTERDIR}/distinfo
PLIST=		${WRKDIR}/plist
RPM_SET=	ttfonts-ja-1.2-21.noarch.rpm

pre-install:
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | cpio -id; \
		${FIND} * -type f -o -type l > ${PLIST}; \
		${FIND} -d * -type d | ${GREP} ja | ${SED} -e 's:^:@dirrm :' \
		>> ${PLIST}

.include "../../x11-toolkits/linux-gtk/Makefile"
