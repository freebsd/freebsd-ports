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
MASTER_SITES=	"" # manual fetch
EXTRACT_SUFX=	.tar

PATCH_SITES=	ftp://ftp.hagenhomes.com/pub/ \
		ftp://ftp.stat.duke.edu/pub/~sto/StarOffice51a/ \
		ftp://ftp.stardivision.de/pub/support/so51a/nwspatch/unxlnxi/ \
		ftp://ftp.stardivision.de/pub/support/so51a/db/unxlnxi/
PATCHFILES=	applicat.rdb libofa517li.so libsdb517li.so

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base \
		${PREFIX}/bin/unzip:${PORTSDIR}/archivers/unzip

MAINTAINER=	dkiwebe@hagenhomes.com

ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Must be downloaded direct from Sun via www interface'
IS_INTERACTIVE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/so51inst

.if !exists(${DISTDIR}/${DISTFILES})
IGNORE="Please manually download ${DISTFILES} from www.sun.com/staroffice or copy them from your Sun StarOffice CDROM.  Put ${DISTFILES} into the directory ${DISTDIR} and run make again."
.endif

post-configure:
	${PERL} -pi.orig -e 's/DefaultDestPath = "Office51";/DefaultDestPath = "${PREFIX}/Office51";/' ${WRKSRC}/office51/setup.ins

do-install:
	unzip -u -L ${WRKDIR}/so51inst/office51/setup.zip -d ${WRKDIR}/tmp
	${ECHO} "${WRKDIR}/tmp" >> /compat/linux/etc/ld.so.conf
	${ECHO} "/tmp/sv001.tmp" >> /compat/linux/etc/ld.so.conf
	PATH=${PATH}:/tmp/sv001.tmp:/usr/compat/linux/tmp/sv001.tmp:/usr/compat/linux/tmp:/tmp
	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/tmp:${WRKDIR}/tmp:/usr/lib:/lib:/tmp:/usr/compat/linux/lib
	/usr/compat/linux/sbin/ldconfig
	${INSTALL_DATA} ${FILESDIR}/dot.sversionrc /root/.sversionrc
	${TOUCH} ${WRKDIR}/.install-done
	${CAT} ${PKGDIR}/MESSAGE
	${WRKDIR}/so51inst/office51/setup /net

post-install:
	${INSTALL_DATA} ${DISTDIR}/applicat.rdb ${PREFIX}/Office51/bin
	${INSTALL_DATA} ${DISTDIR}/libofa517li.so ${PREFIX}/Office51/lib
	${INSTALL_DATA} ${DISTDIR}/libsdb517li.so ${PREFIX}/Office51/lib
	${CHMOD} 100755 ${PREFIX}/Office51/lib/libofa517li.so
	${CHMOD} 100755 ${PREFIX}/Office51/lib/libsdb517li.so
	${PATCH} ${PREFIX}/Office51/bin/setup ${FILESDIR}/setup.patch
	${PATCH} ${PREFIX}/Office51/instdb.ins ${FILESDIR}/instdb.ins.patch
	${PATCH} ${PREFIX}/Office51/bin/soffice ${FILESDIR}/soffice.patch

install-user:
	${PREFIX}/Office51/bin/setup

.include <bsd.port.mk>
