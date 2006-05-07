# New ports collection makefile for:	StarOffice 5.1a
# Date created:		30 October 1999
# Whom:			dkwiebe
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	5.1a
PORTREVISION=	2
CATEGORIES=	editors linux
MASTER_SITES=	http://afug.hypermart.net/files/ \
		ftp://ftp.stat.duke.edu/pub/Users/sto/StarOffice51a/
DISTNAME=	so51a_lnx_01
EXTRACT_SUFX=	.tar
DISTFILES=	applicat.rdb.gz libofa517li.so libsdb517li.so

MAINTAINER=	mb@imp.ch
COMMENT=	Integrated wordprocessor/dbase/spreadheet/drawing/chart/browser

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_LATEST_LINK=	yes
ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Must be downloaded direct from Sun via www interface'

USE_LINUX=	yes
USE_X_PREFIX=	yes
IS_INTERACTIVE=	yes
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=	-u
NO_BUILD=	yes
DIST_SUBDIR=	staroffice5
WRKSRC=		${WRKDIR}/so51inst
TMPDIR=		${WRKDIR}/tmp

.include <bsd.port.pre.mk>

.if defined(WITH_CDROM)
.if !exists(/cdrom/linux/office51/setup.zip)
IGNORE="Please mount the Sun StarOffice 5.1 CDROM onto /cdrom and run make again."
.endif
.else	# FTP/web download
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
.if !exists(${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE="Please manually download ${DISTNAME}${EXTRACT_SUFX} from http://www.sun.com/staroffice.  Put ${DISTNAME}${EXTRACT_SUFX} into the directory ${_DISTDIR} and run make again.  Or, if you have the Sun StarOffice 5.1 CDROM, please run 'make WITH_CDROM=yes'"
.endif
.endif

.if defined(WITH_CDROM)
do-extract:
	@${MKDIR} ${WRKSRC}/office51
	@cd ${WRKSRC}/office51 && ${LN} -s /cdrom/linux/office51/* .
.endif

post-extract:
	@unzip -u -L ${WRKDIR}/so51inst/office51/setup.zip -d ${WRKDIR}/tmp
	@${CP} -p ${_DISTDIR}/applicat.rdb.gz ${WRKDIR}
	@${GZIP_CMD} -d ${WRKDIR}/applicat.rdb.gz

post-configure:
	@${REINPLACE_CMD} -e 's|\(DefaultDestPath = \)"Office51";|\1"${PREFIX}/Office51";|' ${WRKSRC}/office51/setup.ins

do-install:
	@${CP} /compat/linux/etc/ld.so.conf ${TMPDIR}/ld.so.conf.tmp
	@${ECHO} "${WRKDIR}/tmp" >> ${TMPDIR}/ld.so.conf.tmp
	@${ECHO} "/usr/X11R6/lib" >> ${TMPDIR}/ld.so.conf.tmp
	@PATH=${PATH}:${TMPDIR}/sv001.tmp:/compat/linux/tmp/sv001.tmp:/compat/linux/tmp:/tmp
	@LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${TMPDIR}:${WRKDIR}/tmp:/usr/lib:/lib:/tmp:/compat/linux/lib
	@/compat/linux/sbin/ldconfig -f ${TMPDIR}/ld.so.conf.tmp
	@${CAT} ${PKGMESSAGE}
	@-TEMP=${TMPDIR} ${WRKDIR}/so51inst/office51/setup /net
# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

	@${INSTALL_DATA} ${WRKDIR}/applicat.rdb ${PREFIX}/Office51/bin
	@${INSTALL_DATA} ${_DISTDIR}/libofa517li.so ${PREFIX}/Office51/lib
	@${INSTALL_DATA} ${_DISTDIR}/libsdb517li.so ${PREFIX}/Office51/lib
	@${CHMOD} 100755 ${PREFIX}/Office51/lib/libofa517li.so
	@${CHMOD} 100755 ${PREFIX}/Office51/lib/libsdb517li.so
	@${PATCH} -s ${PREFIX}/Office51/bin/setup ${FILESDIR}/setup.patch
	@${PATCH} -s ${PREFIX}/Office51/bin/soffice ${FILESDIR}/soffice.patch
	@${REINPLACE_CMD} -e 's|\(DefaultDestPath = \)"${PREFIX}/Office51";|\1"~/Office51";|' ${PREFIX}/Office51/instdb.ins

install-user:
	${PREFIX}/Office51/bin/setup

.include <bsd.port.post.mk>
