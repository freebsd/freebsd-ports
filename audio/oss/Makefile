# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oss
DISTVERSION=	4.2-build2019
CATEGORIES=	audio
MASTER_SITES=	http://www.opensound.com/developer/sources/stable/bsd/
DISTNAME=	${PORTNAME}-v${DISTVERSION}-src-bsd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Sound System from 4Front Technologies

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	gawk:lang/gawk
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gnome tar:bzip2 kmod pkgconfig
USE_GNOME=	gtk20 cairo gdkpixbuf2
USE_RC_SUBR=	oss

HAS_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ENV=	HOSTCC="${CC}"
ALL_TARGET=	all install

SUB_FILES=	pkg-install pkg-deinstall
LLD_UNSAFE=	yes

KMODDIR=	${PREFIX}/lib/oss/modules

OSS_CONF_FILES=	oss_audigyls oss_audioloop oss_cs461x oss_emu10k1x \
		oss_envy24 oss_envy24ht oss_fmedia oss_hdaudio \
		oss_ich oss_imux oss_madi oss_midiloop oss_sblive \
		oss_sbpci oss_sbxfi oss_trident oss_usb oss_userdev \
		oss_ymf7xx osscore

PROTO_DIR=	${INSTALL_WRKSRC}/prototype
PROTO_ETCDIR=	${PROTO_DIR}/etc
PROTO_BINDIR=	${PROTO_DIR}/usr/bin
PROTO_SBINDIR=	${PROTO_DIR}/usr/sbin
PROTO_MANDIR=	${PROTO_DIR}/usr/share/man
PROTO_OSSLIBDIR=${PROTO_DIR}${PREFIX}/lib/oss

OPTIONS_DEFINE=	VORBIS
OPTIONS_DEFAULT=VORBIS

VORBIS_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis
VORBIS_CONFIGURE_ENV=	OGG_SUPPORT=YES

pre-patch:
	${FIND} ${PATCH_WRKSRC} -name '*.man' -or \
	    \( -name '*.[ch]' \! -name ossmkdep.c \) | \
	    ${XARGS} ${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' \
	    -e 's|/etc/oss|${PREFIX}/etc/oss|g'

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    ${PATCH_WRKSRC}/setup/srcconf.c
	${FIND} ${PATCH_WRKSRC} -name configure -or \
	    -name make.local -or -name soundoff -or -name soundon | \
	    ${XARGS} ${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g'

do-install:
	${INSTALL_PROGRAM} ${PROTO_BINDIR}/* ${STAGEDIR}${PREFIX}/bin/
# @${ECHO_CMD} "OSSLIBDIR=${PREFIX}/lib/oss" > ${PROTO_ETCDIR}/oss.conf
	${INSTALL_DATA} ${PROTO_ETCDIR}/oss.conf ${STAGEDIR}${PREFIX}/etc/
	-@${MKDIR} ${STAGEDIR}${PREFIX}/lib/oss 2>/dev/null
	${INSTALL_DATA} ${PROTO_OSSLIBDIR}/soundon.user \
	    ${STAGEDIR}${PREFIX}/lib/oss/soundon.user.sample
	${INSTALL_DATA} ${PROTO_OSSLIBDIR}/sysfiles.list \
	    ${STAGEDIR}${PREFIX}/lib/oss/
	${INSTALL_DATA} ${PROTO_OSSLIBDIR}/version.dat \
	    ${STAGEDIR}${PREFIX}/lib/oss/
	-@${MKDIR} ${STAGEDIR}${PREFIX}/lib/oss/conf 2>/dev/null
.for CONF_FILE in ${OSS_CONF_FILES}
	${INSTALL_DATA} ${PROTO_OSSLIBDIR}/conf/${CONF_FILE}.conf \
	    ${STAGEDIR}${PREFIX}/lib/oss/conf/${CONF_FILE}.conf.sample
.endfor
	-@${MKDIR} ${STAGEDIR}${PREFIX}/lib/oss/etc 2>/dev/null
	${INSTALL_DATA} ${PROTO_OSSLIBDIR}/etc/devices.list \
	    ${STAGEDIR}${PREFIX}/lib/oss/etc/
	-@${MKDIR} ${STAGEDIR}${PREFIX}/lib/oss/include/sys 2>/dev/null
	${INSTALL_DATA} ${PROTO_OSSLIBDIR}/include/sys/soundcard.h \
	    ${STAGEDIR}${PREFIX}/lib/oss/include/sys/
	${INSTALL_KLD} ${PROTO_OSSLIBDIR}/modules/*.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_MAN} ${PROTO_MANDIR}/man1/*.1.gz \
	    ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${PROTO_MANDIR}/man7/*.7.gz \
	    ${STAGEDIR}${PREFIX}/man/man7/
	${INSTALL_MAN} ${PROTO_MANDIR}/man8/*.8.gz \
	    ${STAGEDIR}${PREFIX}/man/man8/
	${INSTALL_PROGRAM} ${PROTO_SBINDIR}/ossdetect \
	    ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${PROTO_SBINDIR}/ossdevlinks \
	    ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${PROTO_SBINDIR}/savemixer \
	    ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${PROTO_SBINDIR}/soundoff \
	    ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${PROTO_SBINDIR}/soundon \
	    ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${PROTO_SBINDIR}/vmixctl \
	    ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
