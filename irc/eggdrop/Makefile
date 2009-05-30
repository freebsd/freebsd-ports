# New ports collection makefile for:	eggdrop
# Date created:				18.01.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	eggdrop
PORTVERSION=	1.6.19
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.eggheads.org/pub/eggdrop/source/1.6/ \
		LOCAL/beech
DISTNAME=	${PORTNAME}${PORTVERSION}

PATCHFILES=	${PORTNAME}-${PORTVERSION}-ssl-rootie.patch.gz:ssl \
		eggdrop1.6.19+ctcpfix.patch.gz:ctcpfix
PATCH_SITES=	http://www.egghelp.org/files/patches/:ssl \
		ftp://ftp.eggheads.org/pub/eggdrop/patches/official/1.6/:ctcpfix

MAINTAINER=	beech@FreeBSD.org
COMMENT=	The most popular open source Internet Relay Chat bot

USE_TCL=	80+

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcllib=${LOCALBASE}/lib/libtcl${TCL_VER:S/.//}.so \
		--with-tclinc=${TCL_INCLUDEDIR}/tcl.h

OPTIONS=	SSL "Use SSL" off

MAN1=		eggdrop.1

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
CFLAGS+=	-DHAVE_OPENSSL
CONFIGURE_ARGS+=	--with-ssl
.endif

.if !defined(WITH_SSL)
CONFIGURE_ARGS+=	--without-ssl
.endif

post-patch:
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${WRKSRC}/eggdrop.conf \
		> ${WRKSRC}/eggdrop.conf.sample

post-configure:
	@(cd ${WRKSRC}; ${MAKE} config)
# Workaround broken relative path in SSL-patch
	@(cd ${WRKSRC}/src && ${LN} -fs ../config.h)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eggdrop ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man1/eggdrop.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/eggdrop.conf.sample ${PREFIX}/etc
	@${MKDIR} ${PREFIX}/lib/eggdrop
.for f in assoc.so blowfish.so channels.so compress.so console.so ctcp.so \
	dns.so filesys.so irc.so notes.so seen.so server.so share.so \
	transfer.so uptime.so wire.so
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/eggdrop
.endfor
	@${MKDIR} ${DATADIR}/help
.for f in assoc.mod/help/assoc.help channels.mod/help/chaninfo.help \
	channels.mod/help/channels.help console.mod/help/console.help \
	compress.mod/help/compress.help ctcp.mod/help/ctcp.help \
	filesys.mod/help/filesys.help irc.mod/help/irc.help \
	notes.mod/help/notes.help seen.mod/help/seen.help \
	server.mod/help/server.help share.mod/help/share.help \
	transfer.mod/help/transfer.help uptime.mod/help/uptime.help \
	wire.mod/help/wire.help
	${INSTALL_DATA} ${WRKSRC}/src/mod/${f} ${DATADIR}/help
.endfor
	@${MKDIR} ${DATADIR}/help/set
.for f in channels.mod/help/set/channels.help \
	compress.mod/help/set/compress.help \
	console.mod/help/set/console.help ctcp.mod/help/set/ctcp.help \
	filesys.mod/help/set/filesys.help irc.mod/help/set/irc.help \
	notes.mod/help/set/notes.help server.mod/help/set/server.help \
	share.mod/help/set/share.help transfer.mod/help/set/transfer.help
	${INSTALL_DATA} ${WRKSRC}/src/mod/$f ${DATADIR}/help/set
.endfor
	@${MKDIR} ${DATADIR}/help/msg
.for f in irc.mod/help/msg/irc.help notes.mod/help/msg/notes.help \
	seen.mod/help/msg/seen.help
	${INSTALL_DATA} ${WRKSRC}/src/mod/$f ${DATADIR}/help/msg
.endfor
	@${MKDIR} ${DATADIR}/language
	${INSTALL_DATA} ${WRKSRC}/language/core.*.lang ${DATADIR}/language
	@cd ${WRKSRC}/src/mod \
		&& ${FIND} . -name "*.lang" -exec ${INSTALL_DATA} "{}" \
			${DATADIR}/language ";"
	@${MKDIR} ${DATADIR}/scripts
.for f in CONTENTS action.fix.tcl autobotchk alltools.tcl botchk \
	cmd_resolve.tcl compat.tcl getops.tcl klined.tcl notes2.tcl ques5.tcl \
	sentinel.tcl userinfo.tcl weed
	${INSTALL_DATA} ${WRKSRC}/scripts/${f} ${DATADIR}/scripts
.endfor
.for f in cmds1.help cmds2.help core.help
	${INSTALL_DATA} ${WRKSRC}/help/${f} ${DATADIR}/help
.endfor
.for f in cmds1.help
	${INSTALL_DATA} ${WRKSRC}/help/set/${f} ${DATADIR}/help/set
.endfor
	@${MKDIR} ${DATADIR}/text
.for f in banner motd
	${INSTALL_DATA} ${WRKSRC}/text/${f} ${DATADIR}/text
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ABOUT AUTHORS BANS BOTNET BUG-REPORT COMPILE-GUIDE CONTENTS \
	FIRST-SCRIPT KNOWN-PROBLEMS MODULES PARTYLINE PATCH-HOWTO \
	TEXT-SUBSTITUTIONS TRICKS UPDATES1.6 USERS WEIRD-MESSAGES \
	tcl-commands.doc
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/html
	cd ${WRKSRC}/doc/html && ${INSTALL_DATA} *.html ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/settings
	cd ${WRKSRC}/doc/settings && ${INSTALL_DATA} * ${DOCSDIR}/settings
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
