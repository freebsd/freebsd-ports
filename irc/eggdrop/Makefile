# Created by: Ulrich Spoerlein <q@uni.de>
# $FreeBSD$

PORTNAME=	eggdrop
PORTVERSION=	1.8.4
DISTVERSIONPREFIX=	v
CATEGORIES=	irc

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Eggdrop is the most popular Internet Relay Chat (IRC) bot

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tcl ssl

USE_GITHUB=	yes
GH_ACCOUNT=	eggheads

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcllib=${LOCALBASE}/lib/libtcl${TCL_SHLIB_VER}.so \
		--with-tclinc=${LOCALBASE}/include/tcl${TCL_VER}/tcl.h \
		--with-sslinc=${OPENSSLINC} \
		--with-ssllib=${OPENSSLLIB}

MAKE_JOBS_UNSAFE=	yes
LLD_UNSAFE=	yes

SUB_FILES=	pkg-message

CONFLICTS=	eggdrop-devel

OPTIONS_DEFINE=	DOCS

post-patch:
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${WRKSRC}/eggdrop.conf \
		> ${WRKSRC}/eggdrop.conf.sample

post-configure:
	@(cd ${WRKSRC}; ${MAKE} config)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eggdrop ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man1/eggdrop.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/eggdrop.conf.sample ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/eggdrop
.for f in assoc.so blowfish.so channels.so compress.so console.so ctcp.so \
	dns.so filesys.so irc.so notes.so seen.so server.so share.so \
	transfer.so uptime.so
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/lib/eggdrop
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/help
.for f in assoc.mod/help/assoc.help channels.mod/help/chaninfo.help \
	channels.mod/help/channels.help console.mod/help/console.help \
	compress.mod/help/compress.help ctcp.mod/help/ctcp.help \
	filesys.mod/help/filesys.help irc.mod/help/irc.help \
	notes.mod/help/notes.help seen.mod/help/seen.help \
	server.mod/help/server.help share.mod/help/share.help \
	transfer.mod/help/transfer.help uptime.mod/help/uptime.help

	${INSTALL_DATA} ${WRKSRC}/src/mod/${f} ${STAGEDIR}${DATADIR}/help
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/help/set
.for f in channels.mod/help/set/channels.help \
	compress.mod/help/set/compress.help \
	console.mod/help/set/console.help ctcp.mod/help/set/ctcp.help \
	filesys.mod/help/set/filesys.help irc.mod/help/set/irc.help \
	notes.mod/help/set/notes.help server.mod/help/set/server.help \
	share.mod/help/set/share.help transfer.mod/help/set/transfer.help
	${INSTALL_DATA} ${WRKSRC}/src/mod/$f ${STAGEDIR}${DATADIR}/help/set
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/help/msg
.for f in irc.mod/help/msg/irc.help notes.mod/help/msg/notes.help \
	seen.mod/help/msg/seen.help
	${INSTALL_DATA} ${WRKSRC}/src/mod/$f ${STAGEDIR}${DATADIR}/help/msg
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/language
	${INSTALL_DATA} ${WRKSRC}/language/core.*.lang ${STAGEDIR}${DATADIR}/language
	@cd ${WRKSRC}/src/mod \
		&& ${FIND} . -name "*.lang" -exec ${INSTALL_DATA} {} \
			${STAGEDIR}${DATADIR}/language ";"
	@${MKDIR} ${STAGEDIR}${DATADIR}/scripts
.for f in CONTENTS action.fix.tcl autobotchk alltools.tcl botchk \
	cmd_resolve.tcl compat.tcl dccwhois.tcl getops.tcl klined.tcl notes2.tcl ques5.tcl \
	quotepass.tcl quotepong.tcl sentinel.tcl userinfo.tcl weed
	${INSTALL_DATA} ${WRKSRC}/scripts/${f} ${STAGEDIR}${DATADIR}/scripts
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/scripts/help
.for f in cmd_resolve.help userinfo.help
	${INSTALL_DATA} ${WRKSRC}/scripts/help/${f} ${STAGEDIR}${DATADIR}/scripts/help
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/scripts/help/msg
.for f in userinfo.help
	${INSTALL_DATA} ${WRKSRC}/scripts/help/msg/${f} ${STAGEDIR}${DATADIR}/scripts/help/msg
.endfor
.for f in cmds1.help cmds2.help core.help
	${INSTALL_DATA} ${WRKSRC}/help/${f} ${STAGEDIR}${DATADIR}/help
.endfor
.for f in cmds1.help
	${INSTALL_DATA} ${WRKSRC}/help/set/${f} ${STAGEDIR}${DATADIR}/help/set
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/text
.for f in banner motd
	${INSTALL_DATA} ${WRKSRC}/text/${f} ${STAGEDIR}${DATADIR}/text
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ABOUT BANS BOTNET BUG-REPORT COMPILE-GUIDE CONTENTS \
	FIRST-SCRIPT KNOWN-PROBLEMS MODULES PARTYLINE PATCH-HOWTO \
	TEXT-SUBSTITUTIONS TRICKS Changes1.6 USERS WEIRD-MESSAGES \
	tcl-commands.doc
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	cd ${WRKSRC}/doc/html && ${INSTALL_DATA} *.html ${STAGEDIR}${DOCSDIR}/html
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/settings
	cd ${WRKSRC}/doc/settings && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}/settings

.include <bsd.port.mk>
