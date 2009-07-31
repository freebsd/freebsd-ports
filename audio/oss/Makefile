# New ports collection makefile for:	oss
# Date created:		2007-06-14
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oss
DISTVERSION=	4.1-build1052
PORTREVISION=	1
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
MANCOMPRESSED=	yes

MAN1=		ossinfo.1 ossmix.1 osspartysh.1 ossplay.1 ossrecord.1 \
		osstest.1 ossxmix.1 soundoff.1 soundon.1
MAN7=		oss_ali5455.7 oss_allegro.7 oss_atiaudio.7 oss_audigyls.7 \
		oss_audioloop.7 oss_audiopci.7 oss_cmi878x.7 oss_cmpci.7 \
		oss_cs4281.7 oss_cs461x.7 oss_digi96.7 oss_emu10k1x.7 \
		oss_envy24.7 oss_envy24ht.7 oss_fmedia.7 oss_geode.7 \
		oss_hdaudio.7 oss_ich.7 oss_imux.7 oss_midiloop.7 \
		oss_midimix.7 oss_sblive.7 oss_sbpci.7 oss_sbxfi.7 \
		oss_solo.7 oss_trident.7 oss_via823x.7 oss_via97.7 \
		oss_ymf7xx.7 osscore.7
MAN8=		ossdetect.8 ossdevlinks.8 savemixer.8 vmixctl.8

CONF_FILES=	oss_allegro oss_audigyls oss_audioloop oss_cs461x \
		oss_emu10k1x oss_envy24 oss_envy24ht oss_fmedia \
		oss_hdaudio oss_ich oss_imux oss_midiloop oss_sblive \
		oss_sbpci oss_sbxfi oss_trident oss_usb oss_userdev \
		oss_ymf7xx osscore

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
