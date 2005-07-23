# New ports collection makefile for:	linux_base-src-rh-8
# Date created:				2003-09-28
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		linux_base-src-rh-8
PORTVERSION=		8.0
CATEGORIES=		emulators linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX} \
			${MASTER_SITE_REDHAT_LINUX:S/$/:new/}
MASTER_SITE_SUBDIR=	8.0/en/os/i386/SRPMS updates/8.0/en/os/SRPMS/:new
# The rpm and popt sources are packaged together.
DISTFILES=		\
	acl-2.0.11-2.src.rpm \
	attr-2.0.8-3.src.rpm \
	basesystem-8.0-1.src.rpm \
	bash-2.05b-5.src.rpm \
	compat-gcc-7.3-2.96.110.src.rpm \
	filesystem-2.1.6-5.src.rpm \
	fileutils-4.1.9-11.src.rpm \
	gcc-3.2-7.src.rpm \
	gdbm-1.8.0-18.src.rpm \
	glib-1.2.10-8.src.rpm \
	glibc-2.3.2-4.80.8.src.rpm:new \
	grep-2.5.1-4.src.rpm \
	libelf-0.8.2-2.src.rpm \
	libtermcap-2.0.8-31.src.rpm \
	readline-4.3-3.src.rpm \
	redhat-release-8.0-8.src.rpm \
	rpm-4.1-1.06.src.rpm \
	setserial-2.17-9.src.rpm \
	setup-2.5.20-1.src.rpm \
	sh-utils-2.0.12-3.src.rpm \
	termcap-11.0.1-13.src.rpm \
	texinfo-4.2-5.src.rpm
EXTRACT_ONLY=

MAINTAINER=		trevor@FreeBSD.org
COMMENT=		(L)GPL sources for linux_base-8, to comply with licences

BROKEN=			Incomplete pkg-plist
DEPRECATED=		${BROKEN}
EXPIRATION_DATE=	2005-09-22

.undef USE_LINUX

DIST_SUBDIR=		rpm/src/rh-${PORTVERSION}
NO_MTREE=		yes
PLIST=			${WRKDIR}/plist
PREFIX=			${LINUXBASE}

do-build:
	${RM} -f ${PLIST}
.for ii in ${DISTFILES:S/:new//}
	${ECHO_MSG} ${ii}
	${ECHO_CMD} usr/src/redhat/SRPMS/${ii} >> ${PLIST}
.endfor
.for ii in /SRPMS /
	${ECHO_CMD} @dirrm usr/src/redhat${ii} >> ${PLIST}
.endfor

do-install:
	- ${MKDIR} ${PREFIX}/usr/src/redhat/SRPMS
.for ii in ${DISTFILES:S/:new//}
	${CP} -p ${DISTDIR}/${DIST_SUBDIR}/${ii} ${PREFIX}/usr/src/redhat/SRPMS/
.endfor

.include <bsd.port.mk>
