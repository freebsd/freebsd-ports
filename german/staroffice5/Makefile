# New ports collection makefile for: StarOffice 5.1a german
# Date created:		20 Dezember 1999
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	5.1a
PORTREVISION=	2
CATEGORIES=	german editors linux
MASTER_SITES=	ftp://ftp.hagenhomes.com/pub/  \
		ftp://ftp.stat.duke.edu/pub/Users/sto/StarOffice51a/  \
		ftp://ftp.stardivision.de/pub/support/so51a/nwspatch/unxlnxi/  \
		ftp://ftp.stardivision.de/pub/support/so51a/db/unxlnxi/
DISTNAME=	so51a_lnx_49
EXTRACT_SUFX=	.tar
DISTFILES=	applicat.rdb.gz libofa517li.so libsdb517li.so

MAINTAINER=	mb@imp.ch
COMMENT=	Integrated wordprocessor/dbase/spreadheet/drawing/chart/browser

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_LATEST_LINK=	yes
ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_CDROM=	'Sie muessen StarOffice manuell via WWW-Interface herunterladen.'
IS_INTERACTIVE=	yes
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=	-u
NO_BUILD=	yes
DIST_SUBDIR=	staroffice5
USE_PERL5_BUILD=yes
WRKSRC=		${WRKDIR}/so51inst

.include <bsd.port.pre.mk>

.if defined(WITH_CDROM)
.if !exists(${CD_MOUNTPT}/linux/office51/setup.zip)
IGNORE= "Bitte mounten Sie die Sun StarOffice 5.1 CDROM and starten Sie make erneut."
.endif
.else	# FTP/web download
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
.if !exists(${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE="Bitte laden Sie ${DISTNAME}${EXTRACT_SUFX} manuell von http://www.sun.com/staroffice herunter. Kopieren Sie ${DISTNAME}${EXTRACT_SUFX} in das Verzeichnis ${_DISTDIR} und starten Sie make erneut.  Wenn Sie die StarOffice 5.1 CDROM besitzen, koennen Sie auch 'make WITH_CDROM=yes' ausfuehren."
.endif
.endif

.if defined(WITH_CDROM)
do-extract:
	@${MKDIR} ${WRKSRC}/office51
	@cd ${WRKSRC}/office51 && ${LN} -s ${CD_MOUNTPT}/linux/office51/* .
.endif

post-extract:
	@unzip -u -L ${WRKDIR}/so51inst/office51/setup.zip -d ${WRKDIR}/tmp
	@${CP} -p ${_DISTDIR}/applicat.rdb.gz ${WRKDIR}
	@${GZIP_CMD} -d ${WRKDIR}/applicat.rdb.gz

post-configure:
	@${PERL} -pi.orig -e 's|DefaultDestPath = "Office51";|DefaultDestPath = "${PREFIX}/Office51";|' ${WRKSRC}/office51/setup.ins

do-install:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Die Variable DISPLAY ist nicht gesetzt. Setzen Sie entweder
	@ ${ECHO} das DISPLAY manuell oder rufen Sie make mit DISPLAY= und dem
	@ ${ECHO} entsprechenden DISPLAY als Parameter auf.
	@ ${ECHO}
	@ ${FALSE}
.else
.if exists(/compat/linux/usr/local)
	@${LN} -fs /compat/linux/usr/local/Office51 ${PREFIX}/Office51
.endif
	@${CP} /compat/linux/etc/ld.so.conf ${WRKDIR}/tmp/ld.so.conf.temp
	@${ECHO_CMD} "${WRKDIR}/tmp" >> ${WRKDIR}/tmp/ld.so.conf.temp
	@PATH=${PATH}:${WRKDIR}/tmp
	@LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${WRKDIR}/tmp:/usr/lib:/lib:/compat/linux/lib
	@/compat/linux/sbin/ldconfig -f ${WRKDIR}/tmp/ld.so.conf.temp
	@${CAT} ${PKGMESSAGE}
	@-TEMP=${WRKDIR}/tmp ${WRKDIR}/so51inst/office51/setup /net
	@ ${ECHO}
	@ ${ECHO} Ignorieren Sie die Fehlermeldung. StarOffice5.1a wurde erfolgreich
	@ ${ECHO} auf Ihrem System installiert.
	@ ${ECHO}
	@/compat/linux/sbin/ldconfig
.endif

post-install:
	@${INSTALL_DATA} ${WRKDIR}/applicat.rdb ${PREFIX}/Office51/bin
	@${INSTALL_DATA} ${_DISTDIR}/libofa517li.so ${PREFIX}/Office51/lib
	@${INSTALL_DATA} ${_DISTDIR}/libsdb517li.so ${PREFIX}/Office51/lib
	@${PATCH} -s ${PREFIX}/Office51/bin/setup ${FILESDIR}/setup.patch
	@${PATCH} -s ${PREFIX}/Office51/bin/soffice ${FILESDIR}/soffice.patch
	@${CHMOD} 100755 ${PREFIX}/Office51/lib/libofa517li.so
	@${CHMOD} 100755 ${PREFIX}/Office51/lib/libsdb517li.so
	@${PERL} -pi -e 's|DefaultDestPath = "${PREFIX}/Office51";|DefaultDestPath = "~/Office51";|' ${PREFIX}/Office51/instdb.ins
	@${INSTALL_DATA} ${FILESDIR}/dot.sversionrc /root/.sversionrc
# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

install-user:
	${PREFIX}/Office51/bin/setup

.include <bsd.port.post.mk>
