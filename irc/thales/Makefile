# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	thales
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Thales -- An IRC to MySQL gateway

GNU_CONFIGURE=	yes
USES=		gmake
USE_MYSQL=	yes
USE_RC_SUBR=	thales

OPTIONS_DEFINE=	MODES
OPTIONS_RADIO=	IRCD
OPTIONS_RADIO_IRCD=	HYBRID IRCDRU UNREAL
OPTIONS_DEFAULT=MODES UNREAL
MODES_DESC=		Support modes in the database
HYBRID_DESC=	Build for ircd-hybrid
IRCDRU_DESC=	Build for ircd-ru
UNREAL_DESC=	Build for unreal ircd

HYBRID_RUN_DEPENDS=	${LOCALBASE}/bin/ircd:${PORTSDIR}/irc/ircd-hybrid
IRCDRU_RUN_DEPENDS=	${LOCALBASE}/sbin/ircd:${PORTSDIR}/irc/ircd-ru
UNREAL_RUN_DEPENDS=	${LOCALBASE}/libexec/ircd:${PORTSDIR}/irc/unreal

# Currently, not all supported IRCDs are handled here, only the ones
# I could find corresponding RUN_DEPENDS in our Ports Collection.
.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MHYBRID}
_IRCD=	hybrid
IS_INTERACTIVE=	yes
.elif ${PORT_OPTIONS:MIRCDRU}
_IRCD=	ircdru
IS_INTERACTIVE=	yes
.else
_IRCD=	unreal
.endif

# ``Assign with expansion'' is needed here, otherwise we cannot override
# WITH_IRCD value supplied as make(1) argument (which can be bogus).
CONFIGURE_ARGS:=	--with-ircd=${_IRCD} \
			--prefix=${PREFIX}/sbin/thales \
			--with-mysql=${LOCALBASE} \
			--with-mysql-libraries=${LOCALBASE}/lib/mysql

MODES_CONFIGURE_OFF=	--enable-no-modes

post-patch: .SILENT
	${FIND} -d ${WRKSRC} -type d -name CVS -exec ${RM} -rf {} \;
	${REINPLACE_CMD} -e 's,thales.conf,${PREFIX}/etc/&,' \
		${WRKSRC}/src/conf.h

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/thales ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/data/thales.conf.default ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/data/*.sql ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DATADIR}/tools
	${CP} -r ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/tools/* ${STAGEDIR}${DATADIR}/tools

.include <bsd.port.mk>
