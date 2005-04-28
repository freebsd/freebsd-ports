# Ports collection makefile for:	GNU Thales
# Date created:				30 May 2004
# Whom:					Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	thales
PORTVERSION=	1.0
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tux@pinguru.net
COMMENT=	GNU Thales -- An IRC to MySQL gateway

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_MYSQL=	yes
USE_REINPLACE=	yes

# Currently, not all supported IRCDs are handled here, only the ones
# I could find corresponding RUN_DEPENDS in our Ports Collection.
.if defined(WITH_IRCD) && ${WITH_IRCD} == hybrid
RUN_DEPENDS=	${LOCALBASE}/bin/ircd:${PORTSDIR}/irc/ircd-hybrid
IS_INTERACTIVE=	yes
.elif defined(WITH_IRCD) && ${WITH_IRCD} == ircdru
RUN_DEPENDS=	${LOCALBASE}/sbin/ircd:${PORTSDIR}/irc/ircd-ru
IS_INTERACTIVE=	yes
.else
WITH_IRCD=	unreal
RUN_DEPENDS=	${LOCALBASE}/libexec/ircd:${PORTSDIR}/irc/unreal
.endif

# ``Assign with expansion'' is needed here, otherwise we cannot override
# WITH_IRCD value supplied as make(1) argument (which can be bogus).
CONFIGURE_ARGS:=	--with-ircd=${WITH_IRCD}

.if defined(WITHOUT_MODES)
CONFIGURE_ARGS+=	--enable-no-modes
.endif

pre-everything:: .SILENT
	${ECHO_CMD} ""
	${ECHO_CMD} "You may specify the IRCD which thales is compiled for"
	${ECHO_CMD} ""
	${ECHO_CMD} "	WITH_IRCD=foo"
	${ECHO_CMD} ""
	${ECHO_CMD} "The default value is \"unreal\".  Other possible values are:"
	${ECHO_CMD} "  bahamut, hybrid, ircdru, unreal, ultimate28, ultimate30"
	${ECHO_CMD} ""
	${ECHO_CMD} "Additinal tunables:"
	${ECHO_CMD} ""
	${ECHO_CMD} "	WITHOUT_MODES	Disable modes in the database (default: on)"
	${ECHO_CMD} ""

post-patch: .SILENT
	${FIND} -d ${WRKSRC} -type d -name CVS -exec ${RM} -rf {} \;
	${REINPLACE_CMD} -e 's,thales.conf,${PREFIX}/etc/&,' \
		${WRKSRC}/src/conf.h

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/thales ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/thales.conf.default ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/data/*.sql ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR} ${DATADIR}/tools
	${CP} -r ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/tools/* ${DATADIR}/tools
.endif

.include <bsd.port.mk>
