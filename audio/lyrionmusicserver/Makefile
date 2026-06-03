PORTNAME=	lyrionmusicserver
DISTVERSION=	9.1.0
CATEGORIES=	audio

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Audio streaming server that powers Squeezebox players previously from Logitech and many other devices
WWW=		https://lyrion.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/License.txt
# Contains non-redistributable firmware, documentation, and images

ONLY_FOR_ARCHS=		aarch64 amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	Only tested on these archs, set ARCHNAME to value of perl -V:archname for other platforms

BUILD_DEPENDS=	nasm:devel/nasm \
		bash:shells/bash \
		rsync:net/rsync
RUN_DEPENDS=	p5-EV>0:devel/p5-EV \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL

USES=		gmake perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	LMS-Community
GH_PROJECT=	slimserver
GH_TUPLE=	LMS-Community:slimserver-vendor:b62107b:vendor
USE_RC_SUBR=	lyrionmusicserver
SHEBANG_FILES=	Bin/darwin/check-update.pl \
		CPAN/Log/Log4perl/Layout/PatternLayout/Multiline.pm \
		Slim/Plugin/UPnP/t/MediaRenderer.t \
		Slim/Plugin/UPnP/t/MediaServer.t \
		cleanup.pl \
		gdresized.pl \
		lib/MPEG/Audio/Frame.pm \
		scanner.pl \
		slimserver.pl \
		${WRKSRC_vendor}/CPAN/hints/darwin.pl

EXTRACT_AFTER_ARGS=	--exclude .devcontainer \
			--exclude DEVCONTAINERS.md \
			--exclude CPAN/EV.pm \
			--no-same-owner --no-same-permissions

PORTSCOUT=	skipv:10.0.3,10.0.4,release-10.0.0.0

SLIMDIR?=	share/lyrionmusicserver
SLIMDBDIR?=	/var/db/lyrionmusicserver
SLIMUSER?=	slimserv
SLIMGROUP?=	${SLIMUSER}

SUB_FILES=	Custom.pm \
		lyrionmusicserver.conf \
		custom-convert.conf

SUB_LIST=	PERL=${PERL} \
		PORTNAME=${PORTNAME} \
		SITE_PERL=${PREFIX}/${SITE_PERL_REL} \
		SLIMDIR=${SLIMDIR} \
		SLIMDBDIR=${SLIMDBDIR} \
		SLIMUSER=${SLIMUSER} \
		SLIMGROUP=${SLIMGROUP} \
		CONFFILES="${CONFFILES}"

.if ${SLIMUSER} == slimserv
USERS=		${SLIMUSER}
.endif
.if ${SLIMGROUP} == slimserv
GROUPS=		${SLIMGROUP}
.endif

PLIST_SUB=	SLIMDIR=${SLIMDIR} \
		SLIMDBDIR=${SLIMDBDIR} \
		OPSYS=${OPSYS:tl} \
		ARCH=${ARCH} \
		ARCHNAME=${ARCHNAME}

# Defaults support playback of relativly unrestricted formats on SB2 or
# SB3 devices and wired SB1 devices.
OPTIONS_DEFINE=	APE FAAD FLAC LAME SOX TEST DOCS
OPTIONS_DEFAULT=APE FAAD FLAC SOX TEST
SOX_DESC=	Support OGG Vorbis input via SoX (SliMP3 and SB1)
APE_RUN_DEPENDS=	mac:audio/mac
FAAD_RUN_DEPENDS=	faad:audio/faad
FLAC_RUN_DEPENDS=	flac:audio/flac
LAME_RUN_DEPENDS=	lame:audio/lame
SOX_RUN_DEPENDS=	sox:audio/sox
TEST_VARS_OFF=		CONTRIB_FLAGS=-t

DOCFILES=	Changelog*.html License*.txt
CONFFILES=	convert.conf types.conf

.include <bsd.port.pre.mk>

# ARCHNAME=$(shell ${PERL} -V:archname | ${awk} -F\' '{print $2}')
.if ${ARCH} == "i386"
ARCHNAME=	i386-freebsd-thread-multi-64int
.endif

.if ${ARCH} == "amd64"
ARCHNAME=	amd64-freebsd-thread-multi
.endif

.if ${ARCH} == "aarch64"
ARCHNAME=	aarch64-freebsd-thread-multi
.endif

.if ${ARCH} == "powerpc64"
ARCHNAME=	powerpc64-freebsd-thread-multi
.endif

.if ${ARCH} == "powerpc64le"
ARCHNAME=	powerpc64le-freebsd-thread-multi
.endif

do-build:
	cd ${WRKSRC_vendor}/CPAN && ./buildme.sh ${CONTRIB_FLAGS}

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SLIMDIR})
	(cd ${WRKSRC_vendor}/CPAN/build && \
		${COPYTREE_SHARE} arch ${STAGEDIR}${PREFIX}/${SLIMDIR}/CPAN)
	(cd ${WRKSRC_vendor}/CPAN/build/${PERL_VER}/lib/perl5 && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SLIMDIR}/CPAN/arch/${PERL_VER}/)
	(cd ${STAGEDIR}${PREFIX}/${SLIMDIR} && \
		${FIND} . -name \*.orig -delete -o -name \*.bak -delete -o -name \*.packlist -delete && \
		${FIND} ./CPAN/arch/ ! -path './CPAN/arch/${PERL_VER}*' -delete && \
		${RM} -r -- Bin/* .editorconfig .github && \
		${RM} -- ${CONFFILES} ${DOCFILES})
	(cd ${STAGEDIR}${PREFIX}/${SLIMDIR} && \
		${RM} -r -- Firmware/* && \
		${RM} -r -- Graphics/CODE2000*.*)
	(cd ${STAGEDIR}${PREFIX}/${SLIMDIR}/CPAN/arch/${PERL_VER} && \
		${RM} -r -- arm-linux-gnueabihf-thread-multi-64int && \
		${RM} -r -- aarch64-linux-thread-multi && \
		${RM} -r -- i386-linux-thread-multi-64int && \
		${RM} -r -- x86_64-linux-thread-multi)
.for _CONF in ${CONFFILES}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${_CONF} ${STAGEDIR}${PREFIX}/${SLIMDIR}/${_CONF}.sample)
.endfor
	${INSTALL_DATA} ${WRKDIR}/Custom.pm \
	    ${STAGEDIR}${PREFIX}/${SLIMDIR}/Slim/Utils/OS/Custom.pm
	${INSTALL_DATA} ${WRKDIR}/custom-convert.conf \
	    ${STAGEDIR}${PREFIX}/${SLIMDIR}/custom-convert.conf.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${WRKDIR}/lyrionmusicserver.conf \
	    ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/
	@${MKDIR} ${STAGEDIR}${SLIMDBDIR}/cache
	@${RLN} ${STAGEDIR}${SLIMDBDIR}/cache ${STAGEDIR}${PREFIX}/${SLIMDIR}/Cache

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
