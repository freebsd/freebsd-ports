# New ports collection makefile for:	StarOffice 5.1a
# Version required:     5.1a
# Date created:		30 October 1999
# Whom:			dkwiebe
#
# $FreeBSD$
#

DISTNAME=	so51a_lnx_01
PKGNAME=	staroffice-5.1a
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.hagenhomes.com/pub/  \
		ftp://ftp.stat.duke.edu/pub/Users/sto/StarOffice51a/  \
		ftp://ftp.stardivision.de/pub/support/so51a/nwspatch/unxlnxi/  \
		ftp://ftp.stardivision.de/pub/support/so51a/db/unxlnxi/
EXTRACT_SUFX=	.tar
DISTFILES=	applicat.rdb.gz libofa517li.so libsdb517li.so

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

MAINTAINER=	dkiwebe@hagenhomes.com

ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Must be downloaded direct from Sun via www interface'
IS_INTERACTIVE=	yes
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=	-u
NO_BUILD=	yes
DIST_SUBDIR=	staroffice5
WRKSRC=		${WRKDIR}/so51inst

.include <bsd.port.pre.mk>

.if defined(USE_CDROM)
.if !exists(/cdrom/linux/office51/setup.zip)
IGNORE="Please mount the Sun StarOffice 5.1 CDROM onto /cdrom and run make again."
.endif
.else	# FTP/web download
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
.if !exists(${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE="Please manually download ${DISTNAME}${EXTRACT_SUFX} from http://www.sun.com/staroffice.  Put ${DISTNAME}${EXTRACT_SUFX} into the directory ${_DISTDIR} and run make again.  Or, if you have the Sun StarOffice 5.1 CDROM, please run 'make USE_CDROM=yes'"
.endif
.endif

.if defined(USE_CDROM)
do-extract:
	@${MKDIR} ${WRKSRC}/office51
	@cd ${WRKSRC}/office51 && ${LN} -s -v /cdrom/linux/office51/* .
.endif

post-extract:
	@unzip -u -L ${WRKDIR}/so51inst/office51/setup.zip -d ${WRKDIR}/tmp
	@${CP} -p ${_DISTDIR}/applicat.rdb.gz ${WRKDIR}
	@${GZIP_CMD} -d ${WRKDIR}/applicat.rdb.gz

post-configure:
	@${PERL} -pi.orig -e 's|DefaultDestPath = "Office51";|DefaultDestPath = "${PREFIX}/Office51";|' ${WRKSRC}/office51/setup.ins

do-install:
	@${ECHO} "${WRKDIR}/tmp" >> /compat/linux/etc/ld.so.conf
	@${ECHO} "/tmp/sv001.tmp" >> /compat/linux/etc/ld.so.conf
	@PATH=${PATH}:/tmp/sv001.tmp:/usr/compat/linux/tmp/sv001.tmp:/usr/compat/linux/tmp:/tmp
	@LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/tmp:${WRKDIR}/tmp:/usr/lib:/lib:/tmp:/usr/compat/linux/lib
	@/usr/compat/linux/sbin/ldconfig
	@${CAT} ${PKGDIR}/MESSAGE
	@-${WRKDIR}/so51inst/office51/setup /net

# A seperate target as we need to be able to run this stuff independantly.
post-install:
	@${INSTALL_DATA} ${WRKDIR}/applicat.rdb ${PREFIX}/Office51/bin
	@${INSTALL_DATA} ${_DISTDIR}/libofa517li.so ${PREFIX}/Office51/lib
	@${INSTALL_DATA} ${_DISTDIR}/libsdb517li.so ${PREFIX}/Office51/lib
	@${CHMOD} 100755 ${PREFIX}/Office51/lib/libofa517li.so
	@${CHMOD} 100755 ${PREFIX}/Office51/lib/libsdb517li.so
	@${PATCH} -s ${PREFIX}/Office51/bin/setup ${FILESDIR}/setup.patch
	@${PATCH} -s ${PREFIX}/Office51/bin/soffice ${FILESDIR}/soffice.patch
	@${PERL} -pi -e 's|DefaultDestPath = "${PREFIX}/Office51";|DefaultDestPath = "~/Office51";|' ${PREFIX}/Office51/instdb.ins
	@${INSTALL_DATA} ${FILESDIR}/dot.sversionrc /root/.sversionrc

install-user:
	${PREFIX}/Office51/bin/setup

.include <bsd.port.post.mk>
