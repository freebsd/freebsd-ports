# $FreeBSD$

PORTNAME=	logitechmediaserver
PORTVERSION=	7.9.0.g2016.09.30
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	mark@tranquillussoftware.co.uk
COMMENT=	Audio streaming server that powers Squeezebox players from Logitech

LICENSE=	SDL
LICENSE_NAME=	Slim Devices License
LICENSE_FILE=	${WRKSRC}/License.txt
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

BUILD_DEPENDS=	nasm:devel/nasm \
		bash:shells/bash \
		rsync:net/rsync
LIB_DEPENDS=	libgd.so:graphics/gd

USE_GITHUB=	yes
GH_TUPLE=	Logitech:slimserver:c835a1f \
		Logitech:slimserver-vendor:14cc392:vendor

RESTRICTED=	Contains non-redistributable firmware, documentation, and images

USERS=		${SLIMUSER}
GROUPS=		${SLIMGROUP}
USES=		gettext-runtime gmake perl5 shebangfix
EXTRA_PATCHES=	${FILESDIR}/vendorpatch-CPAN_buildme.sh
SHEBANG_FILES=	Bin/darwin/check-update.pl \
		Bin/dbish \
		CPAN/Log/Log4perl/Layout/PatternLayout/Multiline.pm \
		Slim/Plugin/UPnP/t/MediaRenderer.t \
		Slim/Plugin/UPnP/t/MediaServer.t \
		cleanup.pl \
		gdresize.pl \
		gdresized.pl \
		lib/MPEG/Audio/Frame.pm \
		scanner.pl \
		slimserver.pl \
		${WRKSRC_vendor}/CPAN/hints/darwin.pl

# Defaults support playback of relativly unrestricted formats on SB2 or
# SB3 devices and wired SB1 devices.
OPTIONS_DEFINE=	APE FAAD FLAC LAME SHORTEN SOX DOCS
OPTIONS_DEFAULT=APE FAAD FLAX SOX
SHORTEN_DESC=	Support Shorten input
SOX_DESC=	Support OGG Vorbis input via SoX (SliMP3 and SB1)

APE_RUN_DEPENDS=	mac:audio/mac
FAAD_RUN_DEPENDS=	faad:audio/faad
FLAC_RUN_DEPENDS=	flac:audio/flac
LAME_RUN_DEPENDS=	lame:audio/lame
SHORTEN_RUN_DEPENDS=	shorten:audio/shorten
SOX_RUN_DEPENDS=	sox:audio/sox

USE_RC_SUBR=	logitechmediaserver
DOCFILES=	Changelog*.html Installation.txt License*.txt
CONFFILES=	convert.conf types.conf

PLIST_SUB=	SLIMDIR=${SLIMDIR} \
		SLIMDBDIR=${SLIMDBDIR} \
		OPSYS=${OPSYS:tl} \
		ARCH=${ARCH}

SUB_FILES=	Custom.pm \
		custom-convert.conf \
		logitechmediaserver.conf
SUB_LIST=	PERL=${PERL} \
		PORTNAME=${PORTNAME} \
		SITE_PERL=${PREFIX}/${SITE_PERL_REL} \
		SLIMDIR=${SLIMDIR} \
		SLIMDBDIR=${SLIMDBDIR} \
		SLIMUSER=${SLIMUSER} \
		SLIMGROUP=${SLIMGROUP} \
		CONFFILES="${CONFFILES}"

SLIMDIR?=	share/logitechmediaserver
SLIMDBDIR?=	/var/db/logitechmediaserver
SLIMUSER?=	slimserv
SLIMGROUP?=	${SLIMUSER}

do-build:
	cd ${WRKSRC_vendor}/CPAN && ./buildme.sh
	cd ${WRKSRC}/CPAN/arch && ${CP} -R 5.22 5.24

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SLIMDIR})
	(cd ${STAGEDIR}${PREFIX}/${SLIMDIR} && \
		${FIND} . -name \*.orig -delete -o -name \*.bak -delete && \
		${FIND} ./CPAN/arch/ -d 1 ! -name ${PERL_VER} -print0 | ${XARGS} -0 ${RM} -r -- && \
		${RM} -r -- Bin/* && \
		${RM} -- ${CONFFILES} ${DOCFILES})
	(cd ${STAGEDIR}${PREFIX}/${SLIMDIR}/CPAN/arch/${PERL_VER} && \
		${RM} -r -- arm-linux-gnueabihf-thread-multi-64int && \
		${RM} -r -- i386-linux-thread-multi-64int && \
		${RM} -r -- x86_64-linux-thread-multi)
	@${LN} -s ${SLIMDBDIR}/cache ${STAGEDIR}${PREFIX}/${SLIMDIR}/Cache
.for _CONF in ${CONFFILES}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${_CONF} ${STAGEDIR}${PREFIX}/${SLIMDIR}/${_CONF}.sample)
.endfor
	${INSTALL_DATA} ${WRKDIR}/Custom.pm \
	    ${STAGEDIR}${PREFIX}/${SLIMDIR}/Slim/Utils/OS/Custom.pm
	${INSTALL_DATA} ${WRKDIR}/custom-convert.conf \
	    ${STAGEDIR}${PREFIX}/${SLIMDIR}/custom-convert.conf
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${WRKDIR}/logitechmediaserver.conf \
	    ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/
	${INSTALL_SCRIPT} ${WRKSRC}/Bin/dbish ${STAGEDIR}${PREFIX}/${SLIMDIR}/Bin/
	(cd ${WRKSRC_vendor}/CPAN/build && \
		${COPYTREE_SHARE} arch ${STAGEDIR}${PREFIX}/${SLIMDIR}/CPAN)
	(cd ${WRKSRC_vendor}/CPAN/build/${PERL_VER}/lib/perl5 && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SLIMDIR}/CPAN/arch/${PERL_VER}/)
do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
