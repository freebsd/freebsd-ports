# New ports collection makefile for:	eggdrop
# Date created:				18.01.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	eggdrop
PORTVERSION=	1.6.15
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.eggheads.org/pub/eggdrop/source/1.6/
DISTNAME=	${PORTNAME:S/-//}${PORTVERSION}

MAINTAINER=	q@uni.de
COMMENT=	The most popular open source Internet Relay Chat bot

.if !defined(WITHOUT_TCL)
BUILD_DEPENDS+=		${LOCALBASE}/include/tcl8.3/tcl.h:${PORTSDIR}/lang/tcl83
CONFIGURE_ARGS+=	--with-tcllib=${LOCALBASE}/lib/libtcl83.so \
			--with-tclinc=${LOCALBASE}/include/tcl8.3/tcl.h
.endif

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

MAN1=		eggdrop.1

post-patch:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's,modules/,${PREFIX}/lib/eggdrop/,' \
		-e 's,#! /path/to/executable/,#!${PREFIX}/bin/,' eggdrop.conf)

post-configure:
	@(cd ${BUILD_WRKSRC}; ${MAKE} config)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eggdrop ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/man1/eggdrop.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/eggdrop.conf ${PREFIX}/etc/eggdrop.conf.sample
	${MKDIR} ${PREFIX}/lib/eggdrop
	${MKDIR} ${PREFIX}/share/eggdrop ${PREFIX}/share/eggdrop/scripts \
		${PREFIX}/share/eggdrop/language ${PREFIX}/share/eggdrop/help \
		${PREFIX}/share/eggdrop/help/set
	${INSTALL_DATA} ${WRKSRC}/language/core.*.lang \
		${PREFIX}/share/eggdrop/language/
	@cd ${WRKSRC} && ${INSTALL_DATA} assoc.so blowfish.so channels.so \
	compress.so console.so ctcp.so dns.so filesys.so irc.so notes.so seen.so \
	server.so share.so transfer.so uptime.so wire.so ${PREFIX}/lib/eggdrop/
	@cd ${WRKSRC}/src/mod && ${FIND} . -name "*.lang" -exec ${INSTALL_DATA} "{}" \
		${PREFIX}/share/eggdrop/language/ ";"
	@cd ${WRKSRC}/scripts && ${INSTALL_DATA} CONTENTS action.fix.tcl \
		autobotchk alltools.tcl botchk cmd_resolve.tcl compat.tcl getops.tcl \
		klined.tcl notes2.tcl ques5.tcl sentinel.tcl userinfo.tcl weed \
		${PREFIX}/share/eggdrop/scripts/
	@cd ${WRKSRC}/help && ${INSTALL_DATA} cmds1.help cmds2.help core.help \
		${PREFIX}/share/eggdrop/help/
	@cd ${WRKSRC}/help/set && ${INSTALL_DATA} cmds1.help \
		${PREFIX}/share/eggdrop/help/set/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/eggdrop ${PREFIX}/share/eggdrop/html
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} BOTNET tcl-commands.doc tricks \
		${PREFIX}/share/eggdrop/
	@cd ${WRKSRC}/doc/html && ${INSTALL_DATA} *.html ${PREFIX}/share/eggdrop/html
.endif

post-install:
	@${SED} -e 's#$${PREFIX}#${PREFIX}#g' ${PKGMESSAGE}

.include <bsd.port.mk>
