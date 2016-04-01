# $FreeBSD$

PORTNAME=	squeezeboxserver
PORTVERSION=	7.5.4
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://downloads.slimdevices.com/SqueezeboxServer_v${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-noCPAN

MAINTAINER=	markk@knigma.org
COMMENT=	Slim Devices audio streaming server

# Defaults support playback of relativly unrestricted formats on SB2 or
# SB3 devices and wired SB1 devices.
OPTIONS_DEFINE=	APE FAAD FLAC LAME SHORTEN SOX DOCS
OPTIONS_DEFAULT=	APE FAAD FLAX SOX
SHORTEN_DESC=	Support Shorten input
SOX_DESC=	Support OGG Vorbis input via SoX (SliMP3 and SB1)

RESTRICTED=	Contains non-redistributable firmware, documentation, and images

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-32171-noCPAN

RUN_DEPENDS+=	p5-DBIx-Class>=0:databases/p5-DBIx-Class \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-URI-Find>=0:textproc/p5-URI-Find \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Encode-Detect>=0:converters/p5-Encode-Detect \
		p5-GD>=0:graphics/p5-GD \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck \
		p5-EV>=0:devel/p5-EV \
		p5-Audio-Scan>=0.87:audio/p5-Audio-Scan \
		p5-Class-XSAccessor>=0:devel/p5-Class-XSAccessor

# Work around a bug in p5-Package-Stash port
RUN_DEPENDS+=	p5-Package-DeprecationManager>=0.10:devel/p5-Package-DeprecationManager

USERS=		${SLIMUSER}
GROUPS=		${SLIMGROUP}
USES=		perl5 tar:tgz

USE_MYSQL=	server

APE_RUN_DEPENDS=	mac:audio/mac
FAAD_RUN_DEPENDS=	faad:audio/faad
FLAC_RUN_DEPENDS=	flac:audio/flac
LAME_RUN_DEPENDS=	lame:audio/lame
SHORTEN_RUN_DEPENDS=	shorten:audio/shorten
SOX_RUN_DEPENDS=	sox:audio/sox

USE_RC_SUBR=	squeezeboxserver
TMP_SLIMDIR=	${WRKDIR}/_squeezeboxserver
TMP_DOCSDIR=	${WRKDIR}/doc
DOCFILES=	Changelog.html Installation.txt License.txt
CONFFILES=	convert.conf types.conf
EXCEPTFILES=	${DOCFILES} \
		${CONFFILES} \
		CPAN/Carp/Clan.pm \
		CPAN/Class/Accessor.pm \
		CPAN/Class/Accessor/Chained.pm \
		CPAN/Class/C3.pm \
		CPAN/Class/Inspector.pm \
		CPAN/Class/XSAccessor.pm \
		CPAN/Data/Page.pm \
		CPAN/DBI.pm \
		CPAN/EV.pm \
		CPAN/File/Spec.pm \
		CPAN/File/Temp.pm \
		CPAN/File/Which.pm \
		CPAN/GD.pm \
		CPAN/HTML/Parser.pm \
		CPAN/JSON/XS/Boolean.pm \
		CPAN/JSON/XS.pm \
		CPAN/Template.pm \
		CPAN/Test/Simple.pm \
		CPAN/URI.pm \
		CPAN/XML/Parser.pm \
		MySQL/errmsg.txt \
		MySQL/errmsg.sys

EXCEPTDIRS=	Bin \
		CPAN/arch \
		CPAN/Algorith \
		CPAN/Audio \
		CPAN/Compress \
		CPAN/Class/Accessor/Chained \
		CPAN/Class/C3 \
		CPAN/Class/Inspector \
		CPAN/Class/XSAccessor \
		CPAN/DBD \
		CPAN/DBI \
		CPAN/DBIx \
		CPAN/Digest \
		CPAN/Encode \
		CPAN/GD \
		CPAN/Module \
		CPAN/MRO \
		CPAN/Path \
		CPAN/Scope \
		CPAN/File/Spec \
		CPAN/Sub \
		CPAN/SQL \
		CPAN/Template \
		CPAN/URI \
		CPAN/XML/Parser \
		CPAN/YAML

CPIOARGS=	--quiet -pdum -R
PLIST_SUB=	SLIMDIR=${SLIMDIR} \
		SLIMDBDIR=${SLIMDBDIR}

SUB_FILES=	Custom.pm \
		pkg-install \
		softsqueeze.sh \
		custom-convert.conf
SUB_LIST=	PERL=${PERL} \
		PORTNAME=${PORTNAME} \
		SITE_PERL=${PREFIX}/${SITE_PERL_REL} \
		SLIMDIR=${SLIMDIR} \
		SLIMDBDIR=${SLIMDBDIR} \
		SLIMUSER=${SLIMUSER} \
		SLIMGROUP=${SLIMGROUP} \
		CONFFILES="${CONFFILES}"

pre-fetch:
.if !defined(SLIMDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define SLIMDIR to override default of 'squeezeboxserver'."
	@${ECHO_MSG} ""
.endif

SLIMDIR?=	squeezeboxserver
SLIMDBDIR?=	/var/db/squeezeboxserver
SLIMUSER?=	slimserv
SLIMGROUP?=	${SLIMUSER}

post-patch:
	@${REINPLACE_CMD} \
	    -e 's|/usr/bin/perl|${PERL}|g' \
	    -e 's|%%DISTDIR%%|${_DISTDIR}|g' \
	    -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    -e 's|%%PREFIX%%|${PREFIX}|g' \
	    -e 's|%%SITE_PERL%%|${PREFIX}/${SITE_PERL_REL}|g' \
	    -e 's|%%SLIMDBDIR%%|${SLIMDBDIR}|g' \
	    -e 's|%%TMP_SLIMDIR%%|${TMP_SLIMDIR}|g' \
		${WRKSRC}/scanner.pl \
		${WRKSRC}/slimserver.pl
	@${REINPLACE_CMD} \
		-e 's/skip-locking/skip-external-locking/' \
		-e 's/default-character-set/character-set-server/'\
		-e 's/default-collation/collation-server/'  ${WRKSRC}/MySQL/my.tt
# table_open_cache was known as table_cache in MySQL 5.1.2 and earlier
	@if [ "$(MYSQL_VER)" != "50" ] ; then \
		${REINPLACE_CMD} \
			-e 's/table_cache/table_open_cache/' ${WRKSRC}/MySQL/my.tt ;\
	fi
	@${REINPLACE_CMD} \
		-e 's/TYPE=InnoDB/ENGINE=InnoDB/' ${WRKSRC}/SQL/mysql/schema_*.sql

do-build:
	@${MKDIR} -m 0755 ${TMP_SLIMDIR}
	cd ${WRKSRC} && \
	    ${FIND} . -name \*.orig -o -name \*.bak \
	    ${EXCEPTFILES:S|^|-o -path ./|} \
	    ${EXCEPTDIRS:S|^|-o -path ./|} \
	    ${EXCEPTDIRS:S/$/\/\*/:S/^/-o -path .\//} -o -print | \
	    ${CPIO} ${CPIOARGS} ${BINOWN}:${BINGRP} ${TMP_SLIMDIR}
.for _CONF in ${CONFFILES}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${_CONF} ${TMP_SLIMDIR}/${_CONF}.sample
.endfor
do-build-DOCS-on:
	@${MKDIR} ${TMP_DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${TMP_DOCSDIR}

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${PREFIX}/${SLIMDIR}
	@${RM} -f ${STAGEDIR}${PREFIX}/${SLIMDIR}/Cache
	@${LN} -s ${SLIMDBDIR}/cache ${STAGEDIR}${PREFIX}/${SLIMDIR}/Cache
	@cd ${TMP_SLIMDIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SLIMDIR}
	@${INSTALL_DATA} ${WRKDIR}/Custom.pm \
	    ${STAGEDIR}${PREFIX}/${SLIMDIR}/Slim/Utils/OS/Custom.pm
	@${INSTALL_DATA} ${WRKDIR}/custom-convert.conf \
	    ${STAGEDIR}${PREFIX}/${SLIMDIR}/custom-convert.conf
	@${LN} -sf ${LOCALBASE}/share/mysql/errmsg.txt \
	    ${LOCALBASE}/share/mysql/english/errmsg.sys \
	    ${STAGEDIR}${PREFIX}/${SLIMDIR}/MySQL/
	@${INSTALL_SCRIPT} ${WRKDIR}/softsqueeze.sh ${STAGEDIR}${PREFIX}/bin/softsqueeze
do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${TMP_DOCSDIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
