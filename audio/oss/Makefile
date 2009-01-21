# New ports collection makefile for:	oss
# Date created:		2007-06-14
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oss
DISTVERSION=	4.1-build1051
CATEGORIES=	audio kld
MASTER_SITES=	http://www.opensound.com/developer/sources/stable/bsd/
DISTNAME=	${PORTNAME}-v${DISTVERSION}-src-bsd

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Open Sound System

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

USE_BZIP2=	yes
ALL_TARGET=	all install
USE_GNOME=	gtk20
USE_RC_SUBR=	oss
WRKSRC=		${WRKDIR}/build
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
SUB_FILES=	pkg-install pkg-deinstall
ONLY_FOR_ARCHS=	amd64 i386

MAN1=		ossinfo.1.gz ossmix.1.gz osspartysh.1.gz ossplay.1.gz \
		ossrecord.1.gz osstest.1.gz ossxmix.1.gz soundoff.1.gz \
		soundon.1.gz
MAN7=		oss_ali5455.7.gz oss_atiaudio.7.gz oss_audigyls.7.gz \
		oss_audioloop.7.gz oss_audiopci.7.gz oss_cmi878x.7.gz \
		oss_cmpci.7.gz oss_cs4281.7.gz oss_cs461x.7.gz \
		oss_digi96.7.gz	oss_emu10k1x.7.gz oss_envy24.7.gz \
		oss_envy24ht.7.gz oss_fmedia.7.gz oss_geode.7.gz \
		oss_hdaudio.7.gz oss_ich.7.gz oss_imux.7.gz \
		oss_midiloop.7.gz oss_midimix.7.gz oss_sblive.7.gz \
		oss_sbpci.7.gz oss_sbxfi.7.gz oss_solo.7.gz \
		oss_trident.7.gz oss_via823x.7.gz oss_via97.7.gz \
		oss_ymf7xx.7.gz osscore.7.gz
MAN8=		ossdetect.8.gz ossdevlinks.8.gz savemixer.8.gz vmixctl.8.gz

CONF_FILES=	oss_audigyls oss_audioloop oss_cs461x oss_emu10k1x \
		oss_envy24 oss_envy24ht oss_fmedia oss_hdaudio oss_ich \
		oss_imux oss_midiloop oss_sblive oss_sbpci oss_sbxfi \
		oss_trident oss_usb oss_userdev	oss_ymf7xx osscore

PROTO_DIR=	${WRKSRC}/prototype
PROTO_ETCDIR=	${PROTO_DIR}/etc
PROTO_BINDIR=	${PROTO_DIR}/usr/bin
PROTO_SBINDIR=	${PROTO_DIR}/usr/sbin
PROTO_MANDIR=	${PROTO_DIR}/usr/share/man
PROTO_OSSLIBDIR=${PROTO_DIR}${PREFIX}/lib/oss

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source to be installed
.endif

.include <bsd.port.pre.mk>

pre-patch:
	${REINPLACE_CMD} -e 's|"/usr/include/stdarg.h"|<machine/stdarg.h>|g' \
	    -e "s|<i386/include/intr_machdep.h>|<machine/intr_machdep.h>|g" \
	    ${WRKDIR}/${DISTNAME}/setup/FreeBSD/oss/build/module.inc \
	    ${WRKDIR}/${DISTNAME}/setup/FreeBSD/oss/build/osscore.c
	${FIND} ${WRKDIR}/${DISTNAME} -type f \
	    -name configure -or -name '*.[ch]' -or -name '*.man' | \
	    ${XARGS} ${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' \
	    -e 's|/etc/oss|${PREFIX}/etc/oss|g'

post-patch:
	${FIND} ${WRKDIR} -name configure -or -name make.local -or \
	    -name soundoff -or -name soundon | \
	    ${XARGS} ${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g'

do-configure:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${WRKDIR}/${DISTNAME}/configure

do-install:
	${INSTALL_PROGRAM} ${PROTO_BINDIR}/* ${PREFIX}/bin/
# @${ECHO_CMD} "OSSLIBDIR=${PREFIX}/lib/oss" > ${PROTO_ETCDIR}/oss.conf
	${INSTALL_DATA} ${PROTO_ETCDIR}/oss.conf ${PREFIX}/etc/
	-@${MKDIR} ${PREFIX}/lib/oss 2>/dev/null
	${INSTALL_DATA} ${PROTO_OSSLIBDIR}/soundon.user \
	    ${PREFIX}/lib/oss/soundon.user.sample
	${INSTALL_DATA} ${PROTO_OSSLIBDIR}/sysfiles.list ${PREFIX}/lib/oss/
	${INSTALL_DATA} ${PROTO_OSSLIBDIR}/version.dat ${PREFIX}/lib/oss/
	-@${MKDIR} ${PREFIX}/lib/oss/conf 2>/dev/null
.for CONF_FILE in ${CONF_FILES}
	${INSTALL_DATA} ${PROTO_OSSLIBDIR}/conf/${CONF_FILE}.conf \
	    ${PREFIX}/lib/oss/conf/${CONF_FILE}.conf.sample
.endfor
	-@${MKDIR} ${PREFIX}/lib/oss/etc 2>/dev/null
	${INSTALL_DATA} ${PROTO_OSSLIBDIR}/etc/devices.list \
	    ${PREFIX}/lib/oss/etc/
	-@${MKDIR} ${PREFIX}/lib/oss/include/sys 2>/dev/null
	${INSTALL_DATA} ${PROTO_OSSLIBDIR}/include/sys/soundcard.h \
	    ${PREFIX}/lib/oss/include/sys/
	-@${MKDIR} ${PREFIX}/lib/oss/logs 2>/dev/null
	@${MKDIR} ${PREFIX}/lib/oss/modules
	${INSTALL_KLD} ${PROTO_OSSLIBDIR}/modules/*.ko \
	    ${PREFIX}/lib/oss/modules/
	${INSTALL_MAN} ${PROTO_MANDIR}/man1/*.1.gz ${PREFIX}/man/man1/
	${INSTALL_MAN} ${PROTO_MANDIR}/man7/*.7.gz ${PREFIX}/man/man7/
	${INSTALL_MAN} ${PROTO_MANDIR}/man8/*.8.gz ${PREFIX}/man/man8/
	${INSTALL_PROGRAM} ${PROTO_SBINDIR}/ossdetect ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${PROTO_SBINDIR}/ossdevlinks ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${PROTO_SBINDIR}/savemixer ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${PROTO_SBINDIR}/soundoff ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${PROTO_SBINDIR}/soundon ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${PROTO_SBINDIR}/vmixctl ${PREFIX}/sbin/
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
