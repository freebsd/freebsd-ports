# Ports collection makefile for:	slimserver
# Date created:				Wed Apr 14, 2004
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	slimserver
PORTVERSION=	5.1.1
CATEGORIES=	audio
MASTER_SITES=	http://www.slimdevices.com/downloads/SlimServer_v${PORTVERSION}/
DISTNAME=	SlimServer_v${PORTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Slim Devices audio streaming server

RUN_DEPENDS+=	${LOCALBASE}/bin/mDNSResponderPosix:${PORTSDIR}/net/mDNSResponder \
		${SITE_PERL}/Audio/Wav.pm:${PORTSDIR}/audio/p5-Audio-Wav \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec \
		${SITE_PERL}/File/Which.pm:${PORTSDIR}/sysutils/p5-File-Which \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502110
RUN_DEPENDS+=	${LOCALBASE}/bin/pgrep:${PORTSDIR}/sysutils/pkill
.endif

NO_BUILD=	yes
USE_RC_SUBR=	yes
DOCFILES=	Changelog.html Installation.txt
EXCEPTFILES=	${DOCFILES} \
		Changes \
		MANIFEST \
		Makefile.PL \
		README \
		test_tone.wav \
		.exists
EXCEPTDIRS=	Bin \
		CPAN/arch \
		CPAN/Audio/Wav \
		CPAN/Class \
		CPAN/File \
		CPAN/HTTP \
		CPAN/IO \
		CPAN/LWP \
		CPAN/MIME \
		CPAN/MP3 \
		CPAN/Net \
		CPAN/URI

CPIOARGS=	--quiet -pdum -R
PLIST_SUB=	SLIMDIR=${SLIMDIR}

SED_SCRIPT+=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		-e 's,%%SLIMDIR%%,${SLIMDIR},g'

pre-fetch:
.if !defined(SLIMDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define SLIMDIR to override default of 'slimdir'."
	@${ECHO_MSG} ""
.endif

post-patch:
	@${SED} ${SED_SCRIPT} <${FILESDIR}/slimserver.sh >${WRKDIR}/slimserver.sh

SLIMDIR?=	slimserver

pre-install:
	@${SH} ${.CURDIR}/pkg-install ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${SLIMDIR}
	@cd ${WRKSRC} && \
	    ${FIND} . -name \*.orig ${EXCEPTFILES:S/^/-o -name /} \
	    ${EXCEPTDIRS:S/$/\*/:S/^/-o -path .\//} -o -print | \
	    ${CPIO} ${CPIOARGS} ${BINOWN}:${BINGRP} ${PREFIX}/${SLIMDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/slimserver.sh ${PREFIX}/etc/rc.d/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif

post-install:
	@${SH} ${.CURDIR}/pkg-install ${PKGNAME} POST-INSTALL

########################################################################
# The following targets are for the port maintainer.  Use are your own #
# risk, no user-serviceable parts inside.                              #
########################################################################
# Assuming the port is installed cleanly (i.e. it's unconfigured)
# build a pkg-plist file.
build-plist:
	${ECHO} "etc/rc.d/slimserver.sh" > pkg-plist
	${FIND} ${DOCSDIR} -type f | \
	    ${SED} -e 's|${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | \
	    ${SORT} >> pkg-plist
	${FIND} ${PREFIX}/${SLIMDIR}/* -type f | \
	    ${SED} -e 's|${PREFIX}/${SLIMDIR}|%%SLIMDIR%%|' | \
	    ${SORT} >> pkg-plist
	${FIND} ${PREFIX}/${SLIMDIR} -type d | \
	    ${SED} -e 's|${PREFIX}/${SLIMDIR}|@dirrm %%SLIMDIR%%|' | \
	    ${SORT} -r >> pkg-plist
	${FIND} ${DOCSDIR} -type d | \
	    ${SED} -e 's|${DOCSDIR}|%%PORTDOCS%%@dirrm %%DOCSDIR%%|' | \
	    ${SORT} -r >> pkg-plist
	${ECHO} '@unexec rmdir /var/db/slimserver 2>/dev/null || (echo "Configuration information saved.  If you will *NOT* use this package anymore," && echo "please remove /var/db/slimserver and its contents manually.")' >> pkg-plist

.include <bsd.port.post.mk>
