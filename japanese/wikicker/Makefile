# New ports collection makefile for:	WiKicker
# Date created: 			21 Sep 2003
# Whom: 				Fumihiko Kimura <jfkimura@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=		WiKicker
PORTVERSION=		0.26
CATEGORIES+=		japanese www perl5
MASTER_SITES=		http://www.naney.org/comp/distrib/WiKicker/archive/

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Wiki like system by perl5

USE_PERL5=		yes
PERL_CONFIGURE=		yes

# ============================================================================
# =  You have to appoint GPG to use a function to upload an image.           =
# =  If it is necessary, it seems to be    WITH_IMAGEUPLOAD=yes		     =
# ============================================================================

.if defined(WITH_IMAGEUPLOAD)
RUN_DEPENDS+=		${SITE_PERL}/GnuPG/Interface.pm:${PORTSDIR}/security/p5-GnuPG-Interface
.endif
RUN_DEPENDS+=		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
			${SITE_PERL}/Time/Zone.pm:${PORTSDIR}/devel/p5-TimeDate \
			${SITE_PERL}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String \
			${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff \
			${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
			${JCODE}:${PORTSDIR}/japanese/p5-Jcode \
			${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
			${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
			${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl

.if defined(WITH_WIKICKER_RECENTLOG)
RUN_DEPENDS+=		${SITE_PERL}/${PERL_ARCH}/IPC/ShareLite.pm:${PORTSDIR}/devel/p5-IPC-ShareLite
.endif
# DiKicker needed
.if defined(WITH_WIKICKER_DB_FILE_LOCK)
RUN_DEPENDS+=		${SITE_PERL}/DB_File/Lock.pm:${PORTSDIR}/devel/p5-DB_File-Lock
.endif
.if !defined(WITHOUT_WIKICKER_MEMCACHED)
RUN_DEPENDS+=		${SITE_PERL}/Cache/Memcached.pm:${PORTSDIR}/databases/p5-Cache-Memcached
.endif

JCODE=	${SITE_PERL}/Jcode.pm

PKGMESSAGE=		${WRKDIR}/pkg-message
WIKIAUTO=		${SITE_PERL}/auto/${PORTNAME}
WIKIPM=			${SITE_PERL}/${PORTNAME}
WIKISCRIPT=		wiki.cgi.in
MAN3=			WiKicker.3 WiKicker::HTML.3

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG}
	@${ECHO_MSG} "============================================================="
	@${ECHO_MSG} " Install Documents to  ${DOCSDIR}"
	@${ECHO_MSG} "============================================================="

	@${MKDIR} ${DOCSDIR}
.for FILE in AUTHORS ChangeLog NEWS README THANKS
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@cd ${DOCSDIR} && ${FIND} . -type f -o -type l | ${SED} -e 's,^\.,${DOCSDIR:S|${LOCALBASE}/||},' >>${TMPPLIST}
	@cd ${DOCSDIR} && ${FIND} . -type d -depth  | ${SED} -e 's,^\.,@dirrm ${DOCSDIR:S|${LOCALBASE}/||},' >>${TMPPLIST}
.endif

	@${ECHO_MSG}
	@${ECHO_MSG} "============================================================="
	@${ECHO_MSG} " Install Examples to  ${EXAMPLESDIR}"
	@${ECHO_MSG} "============================================================="

	@-${MKDIR} ${EXAMPLESDIR}
.for FILE in htaccess.in wiki.cgi.properties.in wiki.css.in
	${INSTALL_DATA} ${FILESDIR}/${FILE} ${EXAMPLESDIR}/${FILE:S|.in||}
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/${WIKISCRIPT} ${EXAMPLESDIR}/${WIKISCRIPT:S|.in||}
	@cd ${EXAMPLESDIR} && ${FIND} . -type f -o -type l | ${SED} -e 's,^\.,${EXAMPLESDIR:S|${LOCALBASE}/||},' >>${TMPPLIST}
	@cd ${EXAMPLESDIR} && ${FIND} . -type d -depth  | ${SED} -e 's,^\.,@dirrm ${EXAMPLESDIR:S|${LOCALBASE}/||},' >>${TMPPLIST}

	@${ECHO_MSG}
	@${ECHO_MSG} "===>  Making PLIST Phase Start"
	@cd ${PREFIX}; ${FIND} ${WIKIAUTO:S/^${PREFIX}\///} -type f -o -type l | ${SED} -e 's,^\.,${WIKIAUTO:S|${PREFIX}/||},' >>${TMPPLIST}
	@cd ${PREFIX}; ${FIND} ${WIKIAUTO:S/^${PREFIX}\///} -type d | \
		${SORT} -r | ${SED} -e 's/^/@dirrm /' >>${TMPPLIST}
	@cd ${PREFIX}; ${FIND} ${WIKIPM:S/^${PREFIX}\///} -type f -o -type l | ${SED} -e 's,^\.,${WIKIPM:S|${PREFIX}/||},' >>${TMPPLIST}
	@cd ${PREFIX}; ${FIND} ${WIKIPM:S/^${PREFIX}\///} -type d | \
		${SORT} -r | ${SED} -e 's/^/@dirrm /' >>${TMPPLIST}
	@${ECHO_MSG} "===>  Making PLIST Phase End"

	@${SED} -e 's|%%EXAMPLESDIR%%|${EXAMPLESDIR}|' \
		-e 's|%%HostName%%|${HOST}|' < ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
