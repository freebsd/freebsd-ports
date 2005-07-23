# New ports collection makefile for:	linux_base-src-rh-7.3
# Date created:				2003-09-28
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		linux_base-src-rh
PORTVERSION=		7.3
CATEGORIES=		emulators linux
MASTER_SITES=	${MASTER_SITE_REDHAT_LINUX} \
	http://download.fedoralegacy.org/redhat/7.3/updates/SRPMS/:legacy
MASTER_SITE_SUBDIR=	7.3/en/os/i386/SRPMS
# The rpm and popt sources are packaged together.  The libstdc++ and
# compat-libstdc++ binary packages are prepared from the gcc and compat-egcs
# source packages.
# These were omitted:
# 	XFree86-libs-4.3.0-78.EL.src.rpm
# 	bzip2-1.0.2-2.src.rpm
# 	db1-1.85-8.src.rpm
# 	db3-3.3.11-6.src.rpm
# 	ncurses-5.2-26.src.rpm
# 	zlib-1.1.3-25.7.src.rpm
DISTFILES=		\
	glibc-2.2.5-44.legacy.3.src.rpm:legacy \
	redhat-release-7.3-1.src.rpm \
	setup-2.5.12-1.src.rpm \
	filesystem-2.1.6-2.src.rpm \
	basesystem-7.0-2.src.rpm \
	termcap-11.0.1-10.src.rpm \
	gdbm-1.8.0-14.src.rpm \
	glib-1.2.10-5.src.rpm \
	glib2-2.0.1-2.src.rpm \
	libtermcap-2.0.8-28.src.rpm \
	bash-2.05a-13.src.rpm \
	gcc-2.96-110.src.rpm \
	compat-egcs-6.2-1.1.2.16.src.rpm \
	texinfo-4.1-1.src.rpm \
	fileutils-4.1-10.src.rpm \
	grep-2.5.1-1.src.rpm \
	readline-4.2a-4.src.rpm \
	setserial-2.17-5.src.rpm \
	slang-1.4.5-2.src.rpm \
	sh-utils-2.0.11-14.src.rpm \
	rpm-4.0.4-7x.18.src.rpm
EXTRACT_ONLY=

MAINTAINER=		trevor@FreeBSD.org
COMMENT=		GNU GPL sources to linux_base-rh-7.3, to satisfy licence

BROKEN=			Incomplete pkg-plist
DEPRECATED=		${BROKEN}
EXPIRATION_DATE=	2005-09-22

DIST_SUBDIR=		rpm/src/rh-${PORTVERSION}
NO_MTREE=		yes
PLIST=			${WRKDIR}/plist
PLIST_DIRS=		usr/src/redhat/SRPMS usr/src/redhat
PREFIX=			${LINUXBASE}

do-build:
	${RM} -f ${PLIST}
.for ii in ${DISTFILES:S/:legacy//}
	${ECHO_MSG} ${ii}
	${ECHO_CMD} usr/src/redhat/SRPMS/${ii} >> ${PLIST}
.endfor

do-install:
	- ${MKDIR} ${PREFIX}/usr/src/redhat/SRPMS
.for ii in ${DISTFILES:S/:legacy//}
	${CP} -p ${DISTDIR}/${DIST_SUBDIR}/${ii} ${PREFIX}/usr/src/redhat/SRPMS/
.endfor

.include <bsd.port.mk>
