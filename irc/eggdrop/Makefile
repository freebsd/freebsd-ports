# New ports collection makefile for:	eggdrop
# Date created:				18.01.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	eggdrop
PORTVERSION=	1.6.15
PORTREVISION=	4
CATEGORIES=	irc tcl84 ipv6
MASTER_SITES=	ftp://ftp.eggheads.org/pub/eggdrop/source/1.6/
DISTNAME=	${PORTNAME:S/-//}${PORTVERSION}

PATCHFILES=	eggdrop1.6.15-ssl.fixed.diff.gz
PATCH_SITES=	http://www.egghelp.org/files/patches/
PATCH_WRKSRC=	${WRKDIR}

MAINTAINER=	q@uni.de
COMMENT=	The most popular open source Internet Relay Chat bot

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if !defined(WITHOUT_TCL)
LIB_DEPENDS+=		tcl84.1:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcllib=${LOCALBASE}/lib/libtcl84.so \
			--with-tclinc=${LOCALBASE}/include/tcl8.4/tcl.h
.endif

.if defined(WITH_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014 && defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
PLIST_SUB+=		IPV6="@comment "
.else
PLIST_SUB+=		IPV6=""
.endif

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		eggdrop.1

pre-everything::
.if ${OSVERSION} >= 400014 && !defined(WITH_IPV6)
	@${ECHO_MSG} 'Define WITH_IPV6 to enable IPv6 support'
.endif
.if !defined(WITH_SSL)
	@${ECHO_MSG} 'Define WITH_SSL to enable SSL support'
.endif

post-configure:
	@(cd ${WRKSRC}; ${MAKE} config)
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${WRKSRC}/eggdrop.conf \
		> ${WRKSRC}/eggdrop.conf.sample
	# Workaround broken relative path in SSL-patch
	@(cd ${WRKSRC}/src && ${LN} -s ../config.h)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/eggdrop ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/man1/eggdrop.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/eggdrop.conf.sample ${PREFIX}/etc
	@${MKDIR} ${DATADIR}/help/set ${DATADIR}/help/msg ${DATADIR}/scripts \
		${DATADIR}/language ${DATADIR}/text ${PREFIX}/lib/eggdrop
	@${INSTALL_DATA} ${WRKSRC}/language/core.*.lang ${DATADIR}/language
	@cd ${WRKSRC} && ${INSTALL_DATA} assoc.so blowfish.so channels.so \
	compress.so console.so ctcp.so filesys.so irc.so notes.so seen.so \
	server.so share.so transfer.so uptime.so wire.so ${PREFIX}/lib/eggdrop
.if !defined(WITH_IPV6)
	@cd ${WRKSRC} && ${INSTALL_DATA} dns.so ${PREFIX}/lib/eggdrop
.endif
.for f in assoc.mod/help/assoc.help channels.mod/help/chaninfo.help \
	channels.mod/help/channels.help console.mod/help/console.help \
	filesys.mod/help/filesys.help irc.mod/help/irc.help \
	notes.mod/help/notes.help seen.mod/help/seen.help \
	server.mod/help/server.help share.mod/help/share.help
	@${INSTALL_DATA} ${WRKSRC}/src/mod/$f ${DATADIR}/help
.endfor
.for f in channels.mod/help/set/channels.help compress.mod/help/set/compress.help \
	console.mod/help/set/console.help ctcp.mod/help/set/ctcp.help \
	filesys.mod/help/set/filesys.help irc.mod/help/set/irc.help \
	notes.mod/help/set/notes.help server.mod/help/set/server.help \
	transfer.mod/help/set/transfer.help
	@${INSTALL_DATA} ${WRKSRC}/src/mod/$f ${DATADIR}/help/set
.endfor
.for f in irc.mod/help/msg/irc.help notes.mod/help/msg/notes.help \
	seen.mod/help/msg/seen.help
	@${INSTALL_DATA} ${WRKSRC}/src/mod/$f ${DATADIR}/help/msg
.endfor
	@cd ${WRKSRC}/src/mod && ${FIND} . -name "*.lang" -exec ${INSTALL_DATA} "{}" \
		${DATADIR}/language ";"
	@cd ${WRKSRC}/scripts && ${INSTALL_DATA} CONTENTS action.fix.tcl \
		autobotchk alltools.tcl botchk cmd_resolve.tcl compat.tcl getops.tcl \
		klined.tcl notes2.tcl ques5.tcl sentinel.tcl userinfo.tcl weed \
		${DATADIR}/scripts
	@cd ${WRKSRC}/help && ${INSTALL_DATA} cmds1.help cmds2.help core.help \
		${DATADIR}/help
	@cd ${WRKSRC}/help/set && ${INSTALL_DATA} cmds1.help \
		${DATADIR}/help/set
	@cd ${WRKSRC}/text && ${INSTALL_DATA} banner motd ${DATADIR}/text
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/settings ${DOCSDIR}/html
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} BOTNET tcl-commands.doc tricks \
		BUG-REPORT first_script.txt KNOWN-PROBLEMS MODULES PARTYLINE \
		text-substitutions.doc UPDATES1.5 UPDATES1.6 ${DOCSDIR}
	@cd ${WRKSRC}/doc/html && ${INSTALL_DATA} *.html ${DOCSDIR}/html
	@cd ${WRKSRC}/doc/settings && ${INSTALL_DATA} * ${DOCSDIR}/settings
.endif

post-install:
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
